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

static uint32_t *peri = NULL;
static unsigned peri_size = 0;

volatile uint32_t* vc4regmap_init()
{
    int fd;
    unsigned peri_addr;
    long pagesize;
    int err;

    fd = open("/dev/mem", O_RDWR);
    if (fd == -1) {
        fprintf(stderr, "error: open: /dev/mem: %s\n", strerror(errno));
        goto failed_open;
    }

    bcm_host_init();
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
    (void) munmap(peri, peri_size);
failed_mmap:
failed_sysconf:
failed_peri:
    bcm_host_deinit();
    if (fd != -1)
        (void) close(fd);
failed_open:
    return NULL;
}

int vc4regmap_finalize()
{
    int err;

    err = munmap(peri, peri_size);
    if (err) {
        fprintf(stderr, "error: munmap: %s\n", strerror(errno));
        return 1;
    }

    bcm_host_deinit();

    return 0;
}

_Bool is_qpu_enabled(volatile uint32_t *peri)
{
    const uint32_t expected = ('V' << 0) | ('3' << 8) | ('D' << 16);
    if ((peri[V3D_IDENT0] & 0xffffff) == expected)
        return 1;
    return 0;
}
