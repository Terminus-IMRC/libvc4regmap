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
#include <vc4regmap/v3d.h>

    volatile uint32_t* vc4regmap_init();
    int vc4regmap_finalize();
    _Bool is_qpu_enabled(volatile uint32_t *peri);

#endif /* _VC4REGMAP_H_ */
