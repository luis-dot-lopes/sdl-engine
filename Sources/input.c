#include "input.h"

GE_InputState* GE_initInput() {
    GE_InputState *inputSingleton = malloc(sizeof(GE_InputState));

    inputSingleton->quit = false;

    return inputSingleton;
}

void GE_updateInputState(GE_InputState *inputSingleton) {
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0) {
        if(e.type == SDL_QUIT) {
            inputSingleton->quit = true;
        }
    }
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    for(int i = 0; i < 242; i++) {
        if(currentKeyStates[i]) {
            inputSingleton->keysJustPressed[i] = !inputSingleton->keysPressed[i];
            inputSingleton->keysPressed[i] = true;
            inputSingleton->keysReleased[i] = false;
        } else {
            inputSingleton->keysReleased[i] = true;
            inputSingleton->keysPressed[i] = false;
            inputSingleton->keysJustPressed[i] = false;
        }
    }
}
