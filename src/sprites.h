#ifndef DINO_SPRITES_H
#define DINO_SPRITES_H

#include <graphx.h>
#include "gfx/gfx.h"

#define NUM_SMALL_CACTI 4
#define NUM_LARGE_CACTI 2
#define NUM_MOONS 7
#define NUM_STARS 3
#define NUM_HORIZONS 5

#define HORIZON_SEGMENT_WIDTH horizon_0_width
#define SMALL_CACTUS_HEIGHT small_cactus_0_height

#define PTERODACTLY_0_Y_OFFSET 6

extern gfx_rletsprite_t *small_cacti[NUM_SMALL_CACTI];
extern gfx_rletsprite_t *large_cacti[NUM_LARGE_CACTI];
extern gfx_rletsprite_t *moons[NUM_MOONS];
extern gfx_rletsprite_t *stars[NUM_STARS];
extern gfx_rletsprite_t *horizons[NUM_HORIZONS];

#endif //DINO_SPRITES_H
