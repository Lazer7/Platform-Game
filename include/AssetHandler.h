#ifndef CHARACTERHANDLER_H
#define CHARACTERHANDLER_H
#include <vector>
#include <../components/Components.h>
#include "PlayableCharacter.h"
#include "Map.h"
#include "Media.h"


class AssetHandler
{
    public:
        AssetHandler(){};
        void init(SDL_Renderer* renderer);
        void update();
        void render();
        void keyEventHandler(SDL_Event);
        PlayableCharacter newplayer;
        GameObject wall;
    private:
        Map background;
        Media music;

};

#endif // CHARACTERHANDLER_H
