/*
 * Copyright (c) 2019 Sugizaki Yukimasa (ysugi@idein.jp)
 * All rights reserved.
 *
 * This software is licensed under a Modified (3-Clause) BSD License.
 * You should have received a copy of this license along with this
 * software. If not, contact the copyright holder above.
 */

#include <vc4regmap.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define _PASTE(a,b) a##b
#define PASTE(a,b) _PASTE(a,b)

#define BIT(n) (1U << (n))

#define FIELD_GET(name, v) (((v) & PASTE(name, _SET)) >> PASTE(name, _LSB))

#define FIELD_PREP(name, v) (((v) << PASTE(name, _LSB)) & PASTE(name, _SET))

static
void print_dma_info(const uint32_t off_debug)
{
    const uint32_t v = vc4regmap_read(off_debug);
    printf("LITE=%u ", FIELD_GET(DMA0_DEBUG_LITE, v));
    printf("VERSION=0x%x ", FIELD_GET(DMA0_DEBUG_VERSION, v));
    printf("DMA_STATE=0x%03x ", FIELD_GET(DMA0_DEBUG_DMA_STATE, v));
    printf("DMA_ID=0x%02x ", FIELD_GET(DMA0_DEBUG_DMA_ID, v));
    printf("OUTSTANDING_WRITES=0x%x ", FIELD_GET(DMA0_DEBUG_OUTSTANDING_WRITES, v));
    printf("READ_ERROR=%u ", FIELD_GET(DMA0_DEBUG_READ_ERROR, v));
    printf("FIFO_ERROR=%u ", FIELD_GET(DMA0_DEBUG_FIFO_ERROR, v));
    printf("READ_LAST_NOT_SET_ERROR=%u\n", FIELD_GET(DMA0_DEBUG_READ_LAST_NOT_SET_ERROR, v));
}

int main(void)
{
    if (vc4regmap_init() == NULL) {
        fprintf(stderr, "error: vc4regmap_init\n");
        exit(EXIT_FAILURE);
    }

    uint32_t v;

    v = vc4regmap_read(DMA_INT_STATUS);
    printf("INT:");
    for (int i = 0; i < 16; i ++)
        if (v & BIT(i))
            printf(" %d", i);
    printf("\n");

    v = vc4regmap_read(DMA_ENABLE);
    printf("ENABLE:");
    for (int i = 0; i < 16; i ++)
        if (v & BIT(i))
            printf(" %d", i);
    printf("\n");

    printf("DMA0:  "); print_dma_info(DMA0_DEBUG);
    printf("DMA1:  "); print_dma_info(DMA1_DEBUG);
    printf("DMA2:  "); print_dma_info(DMA2_DEBUG);
    printf("DMA3:  "); print_dma_info(DMA3_DEBUG);
    printf("DMA4:  "); print_dma_info(DMA4_DEBUG);
    printf("DMA5:  "); print_dma_info(DMA5_DEBUG);
    printf("DMA6:  "); print_dma_info(DMA6_DEBUG);
    printf("DMA7:  "); print_dma_info(DMA7_DEBUG);
    printf("DMA8:  "); print_dma_info(DMA8_DEBUG);
    printf("DMA9:  "); print_dma_info(DMA9_DEBUG);
    printf("DMA10: "); print_dma_info(DMA10_DEBUG);
    printf("DMA11: "); print_dma_info(DMA11_DEBUG);
    printf("DMA12: "); print_dma_info(DMA12_DEBUG);
    printf("DMA13: "); print_dma_info(DMA13_DEBUG);
    printf("DMA14: "); print_dma_info(DMA14_DEBUG);
    printf("DMA15: "); print_dma_info(DMA15_DEBUG);

    return 0;
}
