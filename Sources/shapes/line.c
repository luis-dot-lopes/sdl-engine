#include "../../Headers/shapes.h"

void GE_Line_draw(GE_GameInstance *game, GE_Line line) {
    SDL_RenderDrawLine(game->renderer, (int) line.x1, (int) line.y1,
                                       (int) line.x2, (int) line.y2);
}
