#ifndef CHARACTERHANDLER_H
#define CHARACTERHANDLER_H
#include <vector>
#include <../components/Components.h>
#include "GameObject.h"



class GameObject;
class CharacterHandler
{
    public:
        CharacterHandler()=default;
        void init(SDL_Renderer* renderer);
        void update();
        void render();
        GameObject newPlayer, newPlayer2;

    private:
        static SDL_Renderer* renderer;


};

#endif // CHARACTERHANDLER_H
