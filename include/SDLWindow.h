#ifndef SDLWINDOW_H
#define SDLWINDOW_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "WindowProperties.h"
#include "AssetHandler.h"



class SDLWindow
{
    public:
        SDLWindow();
        virtual ~SDLWindow();
        void handleEvents();
        void render();
        void update();
        bool running(){return isRunning;}
        void loadMedia(std:: string);
        void capFrameRate(int);
        SDL_Renderer* renderer;
        SDL_Event event;

    protected:

    private:
        SDL_Window* window = NULL;
        SDL_Surface* screen_surface = NULL;
        AssetHandler assetHandler;
        bool isRunning;
};

#endif // SDLWINDOW_H
