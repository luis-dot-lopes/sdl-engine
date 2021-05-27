#include "../../Headers/shapes.h"

bool GE_Rect_collided(GE_Rect rect1, GE_Rect rect2) {
    return rect1.x <= rect2.x + rect2.width  &&
           rect1.x + rect1.width  >= rect2.x &&
           rect1.y <= rect2.y + rect2.height &&
           rect1.y + rect1.height >= rect2.y;
}

GE_Rect GE_Rect_intersection(GE_Rect rect1, GE_Rect rect2) {

}
