#ifndef SDLWINDOW_H
#define SDLWINDOW_H
#include <string>
#include <SDL.h>
#include <stdio.h>
#include <bits/stdc++.h>
class SDLWindow
{
    public:
        SDLWindow();
        SDLWindow(int,int,std::string);
        virtual ~SDLWindow();
        bool init();
        void handleEvents();
        void render();
        SDL_Surface* loadMedia(std:: string);
        SDL_Surface* getSurface();
        SDL_Window* getWindow();
        SDL_Surface* getPicture();
        void delay(int);
        bool running(){return isRunning;}
    protected:

    private:
        int screen_width;
        int screen_height;
        std:: string title;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* screen_surface = NULL;
        SDL_Surface* picture = NULL;
        bool isRunning;
};

#endif // SDLWINDOW_H
