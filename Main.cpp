#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "SDLWindow.h"
using namespace std;

// Window Screen Properties
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const string GAME_TITLE = "Platform Game";

// Testing SDL Libraries
int main(int argv, char** args){
    SDLWindow window(SCREEN_WIDTH,SCREEN_HEIGHT,GAME_TITLE);
    if(!window.init()){
        cout << "Failed to initialize"<< endl;
    }
    else{
        if(!window.loadMedia()){
            cout << "Failed to load media!" << endl;
        }
        else{
            SDL_BlitSurface(window.getPicture(),NULL, window.getSurface(),NULL);
            SDL_UpdateWindowSurface(window.getWindow());
            SDL_Delay( 2000 );
        }
    }
    window.~SDLWindow();
    return 0;
}
