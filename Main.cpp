
#include "SDLWindow.h"
#include "KeyPressSurfaces.h"
// Game Window Properties
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const char GAME_TITLE[] = "Platform Game";

int main( int argc, char* args[] )
{
    SDLWindow game;
    game.init(SCREEN_WIDTH,SCREEN_HEIGHT,GAME_TITLE,true);
    game.loadMedia("./assets/test.bmp");
    while(game.running()){
        game.handleEvents();
        game.render();
        game.update();
        game.delay(80);
    }

    game.~SDLWindow();
	return 0;
}
