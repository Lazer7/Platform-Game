#ifndef ASSETHANDLER_H
#define ASSETHANDLER_H
#include <list>
#include <../components/Components.h>
#include "PlayableCharacter.h"
#include "Map.h"
#include "Media.h"
#include "WindowProperties.h"


class AssetHandler
{
    public:
        AssetHandler(){};
        void init();
        void update();
        void render();
        void keyEventHandler();
        PlayableCharacter newplayer;
        GameObject wall;
    private:
        void addPlatform();
        Map background;
        Media music;
        int frameStart;

};

#endif // ASSETHANDLER_H
