#include "TextureManager.h"
/**
    Creates a texture from an image file

    @param file the image file that will be turned into a SDL_Texture
    @param renderer the current renderer the image will be rendered onto
    @return the texture of the image file
*/
SDL_Texture* TextureManager::loadTexture(char* file, SDL_Renderer* renderer){
        SDL_Surface* tempSurface = IMG_Load(file);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    return texture;
}
