#include "../../Headers/shapes.h"

void GE_Line_draw(GE_GameInstance *game, GE_Line line) {
    SDL_RenderDrawLine(game->renderer, (int) line.x1, (int) line.y1,
                                       (int) line.x2, (int) line.y2);
}

bool GE_Line_vertical(GE_Line line) {
    return line.x1 == line.x2;
}

//helper function
static inline int sign(double x) {
    return (x > 0) - (x < 0);
}

bool GE_Line_intersect(GE_Line line1, GE_Line line2) {

    double a1 = line1.y2 - line1.y1;
    double b1 = line1.x1 - line1.x2;
    double xm1 = line1.x1, ym1 = line1.y1;

    double a2 = line2.y2 - line2.y1;
    double b2 = line2.x1 - line2.x2;
    double xm2 = line2.x1, ym2 = line2.y1;

    return sign(a2 * (line1.x1 - xm2) + b2 * (line1.y1 - ym2)) !=
           sign(a2 * (line1.x2 - xm2) + b2 * (line1.y2 - ym2)) &&
           sign(a1 * (line2.x1 - xm1) + b1 * (line2.y1 - ym1)) !=
           sign(a1 * (line2.x2 - xm1) + b1 * (line2.y2 - ym1));

}

bool GE_Line_getIntersection(GE_Line line1, GE_Line line2, GE_Point *point) {

    bool lines_intersect = GE_Line_intersect(line1, line2);

    if(!lines_intersect) {
        return true;
    } else if() {
    }

    double a1 = (line1.y2 - line1.y1) / (line1.x1 - line1.x2);
    double b1 = line.y1 - a1 * line.x1;

    double a2 = (line2.y2 - line2.y1) / (line2.x1 - line2.x2);
    double b2 = line2.y1 - a2 * line2.x1;

    if(a1 == a2) {
        return false;
    }

    double x = (b2 - b1) / (a1 - a2);

    if(!(line1.x1 <= x && x <= line1.x2 && line2.x1 <= x && x <= line2.x2)) {
        return false;
    }

    double y = a1 * x + b1;

    *point = (GE_Point) {
        .x = x,
        .y = y
    };
}
