
#include "SDLWindow.h"
#include "KeyPressSurfaces.h"
// Game Window Properties
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const char GAME_TITLE[] = "Platform Game";
const int FPS = 120;
int main( int argc, char* args[] )
{
    int frameStart;
    SDLWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,GAME_TITLE,false);
    while(game.running()){
        frameStart = SDL_GetTicks();
        game.handleEvents();
        game.render();
        game.update();
        game.capFrameRate(30,frameStart);
    }

    game.~SDLWindow();

	return 0;
}
