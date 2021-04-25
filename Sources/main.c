#include <stdio.h>
#include <stdbool.h>
#include "engine.h"
#include "input.h"
#include "image.h"

GE_Image* someImg = NULL;

int main(int argc, char* args[]) {

    //Loading game
    GE_GameInstance* game = GE_newGameInstance(640, 480);

    GE_InputState* in = GE_initInput();

    //Loading media
    someImg = GE_loadImage(game, "img.bmp");

    bool gameover = false;

    while(!gameover) {

        GE_updateInputState(in);
        if(in->quit) {
            gameover = true;
            continue;
        }

        //render cycle
        GE_clearScreen(game);

        GE_drawImage(game, 0, 0, someImg);

        GE_renderScreen(game);
    }

    //free resources
    GE_freeImage(someImg);

    someImg = NULL;

    GE_freeGameInstance(game);

    game = NULL;

    return 0;
}
