/*
 * Copyright (c) 2018 Sugizaki Yukimasa (ysugi@idein.jp)
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
#include <time.h>

static uint32_t xorshift32(void)
{
    static _Bool is_init = 1;
    static uint32_t x;

    if (is_init || x == 0) {
        struct timespec t;
        (void) clock_gettime(CLOCK_REALTIME, &t);
        x = t.tv_sec ^ t.tv_nsec;
        is_init = 0;
    }

    x = x ^ (x << 13);
    x = x ^ (x >> 17);
    x = x ^ (x << 15);
    return x;
}

int main(void)
{
    unsigned i;
    const unsigned N = 4096;

    if (vc4regmap_init()) {
        fprintf(stderr, "error: vc4regmap_init\n");
        exit(EXIT_FAILURE);
    }

    if (!is_qpu_enabled()) {
        fprintf(stderr, "error: GRAFX (QPU) is not enabled\n");
        fprintf(stderr, "Use 'qpuinfo -e' or so.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < N; i ++) {
        uint32_t x = xorshift32(), y;
        vc4regmap_write(V3D_SCRATCH, x);
        y = vc4regmap_read(V3D_SCRATCH);
        if (x != y) {
            fprintf(stderr, "Differ at i=%u: 0x%08x vs. 0x%08x\n", i, x, y);
            exit(EXIT_FAILURE);
        }
    }

    if (vc4regmap_finalize()) {
        fprintf(stderr, "error: vc4regmap_finalize\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
