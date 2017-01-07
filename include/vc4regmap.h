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

#ifndef VC4REGMAP_OFFSET
   #define VC4REGMAP_OFFSET 0
#endif /* VC4REGMAP_OFFSET */

#ifndef VC4REGMAP_SHIFT
   #define VC4REGMAP_SHIFT 4
#endif /* VC4REGMAP_SHIFT */

#ifndef VC4REGMAP_TYPE_RW
   #define VC4REGMAP_TYPE_RW uint32_t
#endif /* VC4REGMAP_TYPE_RW */

#ifndef VC4REGMAP_TYPE_RO
   #define VC4REGMAP_TYPE_RO uint32_t
#endif /* VC4REGMAP_TYPE_RO */

#define HW_REGISTER_RW(addr) ((VC4REGMAP_TYPE_RW) addr)
#define HW_REGISTER_RO(addr) ((VC4REGMAP_TYPE_RO) addr)

#include <vc4regmap/v3d.h>

#endif /* _VC4REGMAP_H_ */
