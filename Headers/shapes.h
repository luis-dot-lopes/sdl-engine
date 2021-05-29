#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include "engine.h"
#include <math.h>
#include <SDL.h>
#include <stdbool.h>

typedef struct {
    double x, y, width, height;
} GE_Rect;

//Tests intersection between rects
bool GE_Rect_intersect(GE_Rect rect1, GE_Rect rect2);

//Gets a rect representing intersection between two other rects
GE_Rect GE_Rect_intersection(GE_Rect rect1, GE_Rect rect2);

//Draws a rect
void GE_Rect_draw(GE_GameInstance *game, GE_Rect rect);

//Fills a rect
void GE_Rect_fill(GE_GameInstance *game, GE_Rect rect);

typedef struct {
    double x1, y1, x2, y2;
} GE_Line;

//Draws a line
void GE_Line_draw(GE_GameInstance *game, GE_Line line);

bool GE_Line_intersect(GE_Line line1, GE_Line line2);

#endif // SHAPES_H_INCLUDED