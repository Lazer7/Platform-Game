#ifndef CHARACTERHANDLER_H
#define CHARACTERHANDLER_H
#include <vector>
#include <../components/Components.h>
#include "PlayableCharacter.h"



class CharacterHandler
{
    public:
        CharacterHandler(){};
        void init(SDL_Renderer* renderer);
        void update();
        void render();
        void keyEventHandler(SDL_Event);
        PlayableCharacter newplayer,newplayer2,newplayer3,newplayer4;
    private:
        static SDL_Renderer* renderer;


};

#endif // CHARACTERHANDLER_H
