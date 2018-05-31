
#include "SDLWindow.h"
#include <string>
#include "KeyPressSurfaces.h"
// Game Window Properties
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const std::string GAME_TITLE = "Platform Game";

int main( int argc, char* args[] )
{
    SDLWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,GAME_TITLE);
    game.init();
    while(game.running()){
        game.handleEvents();
        game.render();
        game.delay(80);
    }

    game.~SDLWindow();
	return 0;
}
