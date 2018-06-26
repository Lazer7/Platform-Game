#include "SDLWindow.h"
int main( int argc, char* args[] )
{
    int frameStart;
    SDLWindow game;
    while(game.running()){
        frameStart = SDL_GetTicks();
        game.handleEvents();
        game.render();
        game.update();
        game.capFrameRate(frameStart);
    }
    game.~SDLWindow();
	return 0;
}

