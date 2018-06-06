#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class GameObject
{
    public:
        GameObject(char* spriteSheet, SDL_Renderer* renderer);
        virtual ~GameObject();
        virtual void update()=0;
        virtual void render()=0;

    protected:
        SDL_Texture* objTexture;
        SDL_Renderer* renderer;
        int xpos;
        int ypos;
};

#endif // GAMEOBJECT_H
