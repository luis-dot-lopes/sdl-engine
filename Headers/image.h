#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include "engine.h"
#include <SDL.h>
#include <stdio.h>

typedef struct {
    SDL_Texture* texture;
    int width;
    int height;
} GE_Image;

//Loading images from a path
GE_Image* GE_loadImage(GE_GameInstance *game, const char* path);

//Drawing images to the game screen
void GE_drawImage(GE_GameInstance *game, int x, int y, GE_Image* img);

void GE_freeImage(GE_Image *img);

#endif // IMAGE_H_INCLUDED
