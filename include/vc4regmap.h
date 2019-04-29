/*
 * Copyright (c) 2017 Sugizaki Yukimasa (ysugi@idein.jp)
 * All rights reserved.
 *
 * This software is licensed under a Modified (3-Clause) BSD License.
 * You should have received a copy of this license along with this
 * software. If not, contact the copyright holder above.
 */

#ifndef _VC4REGMAP_H_
#define _VC4REGMAP_H_

#include <stdint.h>

#define HW_REGISTER_RW(addr) ((uint32_t) ((((addr)) >> 2)))
#define HW_REGISTER_RO HW_REGISTER_RW
#include <vc4regmap/v3d.h>
#include <vc4regmap/i2c_spi_slv.h>
#include <vc4regmap/cpr_powman.h>
#include <vc4regmap/cpr_clkman.h>
#include <vc4regmap/axi_dma_top.h>
#include <vc4regmap/axi_dma0.h>
#include <vc4regmap/axi_dma1.h>
#include <vc4regmap/axi_dma2.h>
#include <vc4regmap/axi_dma3.h>
#include <vc4regmap/axi_dma4.h>
#include <vc4regmap/axi_dma5.h>
#include <vc4regmap/axi_dma6.h>
#include <vc4regmap/axi_dma_lite7.h>
#include <vc4regmap/axi_dma_lite8.h>
#include <vc4regmap/axi_dma_lite9.h>
#include <vc4regmap/axi_dma_lite10.h>
#include <vc4regmap/axi_dma_lite11.h>
#include <vc4regmap/axi_dma_lite12.h>
#include <vc4regmap/axi_dma_lite13.h>
#include <vc4regmap/axi_dma_lite14.h>
#include <vc4regmap/axi_dma15.h>

    volatile uint32_t* vc4regmap_init(void);
    int vc4regmap_finalize(void);
    uint32_t vc4regmap_read(const uint32_t offs);
    void vc4regmap_write(const uint32_t offs, const uint32_t val);
    _Bool is_qpu_enabled(void);

#endif /* _VC4REGMAP_H_ */
