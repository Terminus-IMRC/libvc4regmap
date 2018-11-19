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

int main(void)
{
    uint32_t id0, id1, id2, id3;
    int err;

    if (vc4regmap_init() == NULL) {
        fprintf(stderr, "error: vc4regmap_init\n");
        exit(EXIT_FAILURE);
    }

    if (!is_qpu_enabled()) {
        fprintf(stderr, "error: GRAFX (QPU) is not enabled\n");
        fprintf(stderr, "Use 'qpuinfo -e' or so.\n");
        exit(EXIT_FAILURE);
    }

    id0 = vc4regmap_read(V3D_IDENT0);
    id1 = vc4regmap_read(V3D_IDENT1);
    id2 = vc4regmap_read(V3D_IDENT2);
    id3 = vc4regmap_read(V3D_IDENT3);

    printf("V3D Identification 0 = 0x%08x\n", id0);
    printf("V3D Identification 1 = 0x%08x\n", id1);
    printf("V3D Identification 2 = 0x%08x\n", id2);
    printf("V3D Identification 3 = 0x%08x\n", id3);

    if (id0 == id1) {
        fprintf(stderr, "error: IDENT0 and IDENT1 is the same"
                " (accessing peripheral with vld/vst)\n");
        exit(EXIT_FAILURE);
    }

    err = vc4regmap_finalize();
    if (err) {
        fprintf(stderr, "error: vc4regmap_finalize: %d\n", err);
        exit(EXIT_FAILURE);
    }

    return 0;
}
