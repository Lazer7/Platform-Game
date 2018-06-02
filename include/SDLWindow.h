#ifndef SDLWINDOW_H
#define SDLWINDOW_H

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

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
        void delay(int);
    protected:

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* screen_surface = NULL;
        SDL_Surface* picture = NULL;
        bool isRunning;
};

#endif // SDLWINDOW_H
