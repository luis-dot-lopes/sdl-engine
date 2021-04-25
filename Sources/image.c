#include "image.h"

GE_Image* GE_loadImage(GE_GameInstance *game, const char* path) {
    GE_Image* newImage = malloc(sizeof(GE_Image));
    if(newImage == NULL) {
        return NULL;
    }

    SDL_Surface* imgSurface = _GE_loadSurface(game, path);
    if( imgSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, SDL_GetError() );
        return NULL;
    } else {

        newImage->width = imgSurface->w;
        newImage->height = imgSurface->h;

        Uint32 colorKey = SDL_MapRGB(imgSurface->format, 255, 0, 255);
        SDL_SetColorKey(imgSurface, SDL_TRUE, colorKey);

        //Create texture from surface pixels
        SDL_Texture *newTexture = SDL_CreateTextureFromSurface( game->renderer, imgSurface );
        if( newTexture == NULL ) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
            return NULL;
        }

        newImage->texture = newTexture;

        //Get rid of old loaded surface
        SDL_FreeSurface( imgSurface );
    }

    return newImage;
}

void GE_drawImage(GE_GameInstance *game, int x, int y, GE_Image *img) {
    SDL_Rect imgRect = {x, y, img->width, img->height};

    SDL_RenderCopy(game->renderer, img->texture, NULL, &imgRect);
}

void GE_freeImage(GE_Image *img) {
    SDL_DestroyTexture(img->texture);

    free(img);
}
