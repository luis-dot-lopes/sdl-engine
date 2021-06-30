#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include "../Headers/engine.h"

//A struct representing red, green, blue and alpha values
typedef struct {

    int r;
    int g;
    int b;
    int a;

} GE_Color;

//Representation of some colors
const GE_Color GE_WHITE   = { 0xFF, 0xFF, 0xFF, 0xFF };
const GE_Color GE_BLACK   = { 0x00, 0x00, 0x00, 0xFF };
const GE_Color GE_GREY    = { 0x80, 0x80, 0x80, 0xFF };

const GE_Color GE_RED     = { 0xFF, 0x00, 0x00, 0xFF };
const GE_Color GE_GREEN   = { 0x00, 0xFF, 0x00, 0xFF };
const GE_Color GE_BLUE    = { 0x00, 0x00, 0xFF, 0xFF };

const GE_Color GE_YELLOW  = { 0xFF, 0xFF, 0x00, 0xFF };
const GE_Color GE_CYAN    = { 0x00, 0xFF, 0xFF, 0xFF };
const GE_Color GE_MAGENTA = { 0xFF, 0x00, 0xFF, 0xFF };

const GE_Color GE_BROWN   = { 0x8B, 0x45, 0x13, 0xFF };
const GE_Color GE_ORANGE  = { 0xFF, 0x8C, 0x00, 0xFF };
const GE_Color GE_PINK    = { 0xFF, 0xC0, 0xCB, 0xFF };

//Changes color based on color struct value
void GE_setColor(GE_GameInstance *game, GE_Color color) {

    GE_changeColor(game, color.r, color.g, color.b, color.a);

}


#endif // COLOR_H_INCLUDED
