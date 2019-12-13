#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphx.h>
#include <keypadc.h>
#include <debug.h>

#include "graphics.h"
#include "gamestate.h"
#include "util.h"
#include "physics.h"

void reset_timer(void) {
    timer_Control = TIMER1_DISABLE;
    timer_1_Counter = 0;
    timer_1_MatchValue_1 = FRAME_TIME;
    timer_Control = TIMER1_ENABLE | TIMER1_32K | TIMER1_NOINT | TIMER1_UP;
}

void play(game_t *game) {
    do {
        kb_Scan();

        game->dino.ducking = kb_IsDown(kb_KeyDown) && game->dino.on_ground;
        game->dino.dropping = kb_IsDown(kb_KeyDown) && !game->dino.on_ground;
        game->dino.jumping = kb_IsDown(kb_KeyUp);

        update_physics(game);

        draw(game);

        while(!(timer_IntStatus & TIMER1_MATCH1)) {
            kb_Scan();
            if(kb_IsDown(kb_KeyClear)) break;
        }
        reset_timer();

        game->frame++;

    } while(!kb_IsDown(kb_KeyClear));
}

void main(void) {
    game_t game = {0};
    init_graphics();


    reset_timer();
    game.dino.on_ground = true;
    game.dino.y.combined = INT_TO_FIXED_POINT(GROUND_LEVEL);
    game.dino.velocity_x.combined = INT_TO_FIXED_POINT(6);
    game.dino.velocity_y.combined = 0;

    play(&game);

    gfx_End();
}
