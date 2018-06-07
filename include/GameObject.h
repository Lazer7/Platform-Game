#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
#include <SDL_image.h>
#include "../components/Components.h"

class GameObject
{
    public:
        GameObject(char* spriteSheet, SDL_Renderer* renderer);
        virtual ~GameObject();
        virtual void update()=0;
        virtual void render()=0;
        static SDL_Renderer* renderer;
    protected:
        SDL_Texture* objTexture;

};

#endif // GAMEOBJECT_H
