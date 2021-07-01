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

//Declaration of some colors constants
const GE_Color GE_WHITE;
const GE_Color GE_BLACK;
const GE_Color GE_GREY;

const GE_Color GE_RED;
const GE_Color GE_GREEN;
const GE_Color GE_BLUE;

const GE_Color GE_YELLOW;
const GE_Color GE_CYAN;
const GE_Color GE_MAGENTA;

const GE_Color GE_BROWN;
const GE_Color GE_ORANGE;
const GE_Color GE_PINK;

//Changes color based on color struct value
void GE_setColor(GE_GameInstance *game, GE_Color color);

//Makes the color brighter by given percentage
GE_Color GE_lightenColor(GE_Color color, float percent);

//Makes the color darker by given percentage
GE_Color GE_darkenColor(GE_Color color, float percent);

#endif // COLOR_H_INCLUDED
