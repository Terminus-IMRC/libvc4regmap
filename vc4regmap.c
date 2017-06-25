#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <bcm_host.h>
#include <qmkl.h>
#include "vc4regmap.h"

static int mbfd = -1;
static unsigned peri_addr, peri_size;

void vc4regmap_init()
{
    bcm_host_init();

    mbfd = mailbox_open();
    if (mailbox_qpu_enable(mbfd, 1)) {
        fprintf(stderr, "%s:%d: Failed to enable QPU\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    peri_addr = bcm_host_get_peripheral_address();
    peri_size = bcm_host_get_peripheral_size();
}

void vc4regmap_finalize()
{
    mailbox_qpu_enable(mbfd, 0);
    mailbox_close(mbfd);
    bcm_host_deinit();
}

volatile uint32_t* vc4regmap_map_peri()
{
    return map_on_cpu(BUS_TO_PHYS(peri_addr), peri_size);
}

void vc4regmap_unmap_peri(volatile uint32_t *peri)
{
    unmap_on_cpu((void*) peri, peri_size);
}

_Bool is_qpu_enabled(volatile uint32_t *peri)
{
    const uint32_t expected = ('V' << 0) | ('3' << 8) | ('D' << 16);
    if ((peri[V3D_IDENT0] & 0xffffff) == expected)
        return !0;
    return 0;
}
