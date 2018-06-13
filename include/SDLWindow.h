#ifndef SDLWINDOW_H
#define SDLWINDOW_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "CharacterHandler.h"
#include "Media.h"
#include "Map.h"

class SDLWindow
{
    public:
        SDLWindow(int,int,std:: string,bool);
        virtual ~SDLWindow();
        void handleEvents();
        void render();
        void update();
        bool running(){return isRunning;}

        void loadMedia(std:: string);
        void capFrameRate(int,int);
        SDL_Renderer* renderer;
        SDL_Event event;

    protected:

    private:
        SDL_Window* window = NULL;
        SDL_Surface* screen_surface = NULL;
        CharacterHandler characterHandler;
        Map background;
        Media music;
        bool isRunning;
};

#endif // SDLWINDOW_H
