#ifndef SDLWINDOW_H
#define SDLWINDOW_H

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

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
        static SDL_Renderer* renderer;
        static SDL_Event event;
    protected:

    private:
        SDL_Window* window = NULL;
        SDL_Surface* screen_surface = NULL;
        SDL_Texture* background;
        bool isRunning;
};

#endif // SDLWINDOW_H
