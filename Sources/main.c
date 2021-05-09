#include <stdio.h>
#include <stdbool.h>
#include "../Headers/engine.h"
#include "../Headers/input.h"
#include "../Headers/image.h"
#include "../Headers/clock.h"

GE_Sprites* someImg = NULL;

int main(int argc, char* args[]) {

    //Loading game
    GE_GameInstance* game = GE_newGameInstance(640, 480);

    GE_InputState* in = GE_initInput();

    GE_Clock clock = GE_newClock(60);

    //Loading media
    someImg = GE_loadSprites(game, "img.bmp", 100);

    bool gameover = false;

    while(!gameover) {
        GE_clockInitTick(&clock);

        GE_updateInputState(in);
        if(in->quit) {
            gameover = true;
            continue;
        }

        //render cycle
        GE_clearScreen(game);

        GE_drawSprite(game, 0, 0, someImg);

        GE_renderScreen(game);

        GE_clockEndTick(&clock);
    }

    //free resources
    GE_freeSprites(someImg);

    someImg = NULL;

    GE_freeInputState(in);

    in = NULL;

    GE_freeGameInstance(game);

    game = NULL;

    return 0;
}
