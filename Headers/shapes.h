#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

typedef struct {
    double x, y, width, height;
} GE_Rect;

//Tests collision between rects
bool GE_Rect_collided(GE_Rect rect1, GE_Rect rect2);

//Gets a rect representing intersection between two other rects
GE_Rect GE_Rect_intersection(GE_Rect rect1, GE_Rect rect2);

#endif // SHAPES_H_INCLUDED
