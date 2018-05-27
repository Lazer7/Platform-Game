#include "SDLWindow.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;
SDLWindow::SDLWindow(int width, int height, std::string title)
{
    //ctor
    this->screen_width = width;
    this->screen_height = height;
    this->title=title;
}

SDLWindow::~SDLWindow()
{
    //Deallocate surface
    SDL_FreeSurface( this->picture );
    this->picture = NULL;

    //Destroy window
    SDL_DestroyWindow( this->window );
    this->window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
    //dtor
}
bool SDLWindow:: init(){
    //Initialization flag
    bool success = true;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        char title_array[this->title.length()+1];
        strcpy(title_array, this->title.c_str());
        //Create window
        this->window = SDL_CreateWindow( title_array, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->screen_width, this->screen_height, SDL_WINDOW_SHOWN );
        if( this->window== NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            this->screen_surface = SDL_GetWindowSurface( this->window );
        }
    }
    return success;
}
SDL_Surface* SDLWindow::loadMedia(std::string path)
{
    //Load splash image
    this->picture = SDL_LoadBMP(path.c_str());
    if( this->picture == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "image", SDL_GetError() );
    }
    return this->picture;
}

SDL_Surface* SDLWindow:: getSurface(){
    return this->screen_surface;
}
SDL_Window* SDLWindow:: getWindow(){
    return this->window;
}
SDL_Surface* SDLWindow:: getPicture(){
    return this->picture;
}
