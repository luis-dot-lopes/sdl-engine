#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "input.h"
#include <stdbool.h>
#include <SDL.h>

typedef struct {
    bool keysPressed[242];
    bool keysReleased[242];
    bool keysJustPressed[242];
    bool quit;
} GE_InputState;

//Initializes input state
GE_InputState* GE_initInput();

//Update input
void GE_updateInputState(GE_InputState *inputSingleton);

#endif // INPUT_H_INCLUDED
