#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <bcm_host.h>
#include <mailbox.h>
#include "vc4regmap.h"

static int mbfd = -1;
static unsigned peri_addr, peri_size;

void vc4regmap_init()
{
	bcm_host_init();
	mbfd = mbox_open();
	if (qpu_enable(mbfd, 1)) {
		fprintf(stderr, "%s:%d: Failed to enable QPU\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}
	peri_addr = bcm_host_get_peripheral_address();
	peri_size = bcm_host_get_peripheral_size();
}

void vc4regmap_finalize()
{
	qpu_enable(mbfd, 0);
	mbox_close(mbfd);
	bcm_host_deinit();
}

uint32_t* vc4regmap_map_peri()
{
	return mapmem_cpu(BUS_TO_PHYS(peri_addr), peri_size);
}

void vc4regmap_unmap_peri(uint32_t *peri)
{
	unmapmem_cpu(peri, peri_size);
}
