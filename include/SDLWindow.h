#ifndef SDLWINDOW_H
#define SDLWINDOW_H
#include <string>
#include <SDL.h>
#include <stdio.h>

class SDLWindow
{
    public:
        SDLWindow();
        SDLWindow(int,int,std::string);
        virtual ~SDLWindow();
        bool init();
        bool loadMedia();
        SDL_Surface* getSurface();
        SDL_Window* getWindow();
        SDL_Surface* getPicture();
    protected:

    private:
        int screen_width;
        int screen_height;
        std:: string title;
        SDL_Window* window;
        SDL_Surface* screen_surface = NULL;
        SDL_Surface* picture = NULL;
};

#endif // SDLWINDOW_H
