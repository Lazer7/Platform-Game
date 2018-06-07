#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDLWindow.h>

class TextureManager
{
    public:
        static SDL_Texture* loadTexture(const char*);
        static void Draw(SDL_Texture*,SDL_Rect,SDL_Rect);
};

#endif // TEXTUREMANAGER_H
