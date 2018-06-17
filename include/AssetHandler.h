#ifndef ASSETHANDLER_H
#define ASSETHANDLER_H
#include <list>
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
        void addPlatform();
        SDL_Renderer* renderer;
        Map background;
        Media music;
        int frameStart;

};

#endif // ASSETHANDLER_H
