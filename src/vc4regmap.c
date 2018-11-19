#if !defined(__arm__) && !defined(__aarch64__)
#error "This code is for AArch32 and AArch64 only"
#endif /* !defined(__arm__) && !defined(__aarch64__) */

#if defined(__arm__) && defined(__aarch64__)
#error "__arm__ and __aarch64__ are both defined???"
#endif /* defined(__arm__) && defined(__aarch64__) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <bcm_host.h>
#include "vc4regmap.h"

static volatile uint32_t *peri = NULL;
static unsigned peri_size = 0;

volatile uint32_t* vc4regmap_init(void)
{
    int fd;
    unsigned peri_addr;
    long pagesize;
    int err;

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd == -1) {
        fprintf(stderr, "error: open: /dev/mem: %s\n", strerror(errno));
        goto failed_open;
    }

    peri_addr = bcm_host_get_peripheral_address();
    peri_size = bcm_host_get_peripheral_size();

    pagesize = sysconf(_SC_PAGESIZE);
    if (pagesize <= 0) {
        fprintf(stderr, "error: sysconf: %s\n", strerror(errno));
        goto failed_sysconf;
    }

    if (peri_addr & (((unsigned) pagesize) - 1)) {
        fprintf(stderr, "error: peri_addr is not aligned to page size\n");
        goto failed_peri;
    }

    peri = mmap(NULL, peri_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
            peri_addr);
    if (peri == MAP_FAILED) {
        fprintf(stderr, "error: mmap: %s\n", strerror(errno));
        goto failed_mmap;
    }

    err = close(fd);
    if (err) {
        fprintf(stderr, "error: close: %s\n", strerror(errno));
        fd = -1;
        goto failed_close;
    }

    return peri;

failed_close:
    (void) munmap((void*) peri, peri_size);
failed_mmap:
failed_sysconf:
failed_peri:
    if (fd != -1)
        (void) close(fd);
failed_open:
    peri = NULL;
    return NULL;
}

int vc4regmap_finalize(void)
{
    int err;

    err = munmap((void*) peri, peri_size);
    if (err) {
        fprintf(stderr, "error: munmap: %s\n", strerror(errno));
        return 1;
    }

    peri = NULL;
    return 0;
}

/* Peripheral reading/writing functions.  The assembly is needed because the
 * peripheral cannot be accessed with vld/vst instruction.
 */

/* For assembly constraints, see
 * https://gcc.gnu.org/onlinedocs/gcc/Constraints.html
 */

uint32_t vc4regmap_read(const uint32_t offs)
{
    uint32_t val;

    asm volatile (
#ifdef __arm__
            "ldr %[value], [%[addr]]\n\t"
#elif defined(__aarch64__)
            "ldr %w[value], [%[addr]]\n\t"
#endif
            : [value] "=r" (val)
            : [addr] "r" (peri + offs)
            : "memory"
    );

    return val;
}

void vc4regmap_write(const uint32_t offs, const uint32_t val)
{
    asm volatile (
#if defined(__arm__)
            "str %[value], [%[addr]]\n\t"
#elif defined(__aarch64__)
            "str %w[value], [%[addr]]\n\t"
#endif
            :
            : [value] "r" (val),
              [addr] "r" (peri + offs)
            : "memory"
    );
}

_Bool is_qpu_enabled(void)
{
    const uint32_t expected = ('V' << 0) | ('3' << 8) | ('D' << 16) | (2 << 24);
    if (vc4regmap_read(V3D_IDENT0) == expected)
        return 1;
    return 0;
}
