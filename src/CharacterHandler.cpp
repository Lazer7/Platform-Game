#include "CharacterHandler.h"

/**
    Initializes all Character Assets in the Game
    TODO:: Refactor to place all characters in a vector
    @param renderer the rendering engine to place all game objects
*/
void CharacterHandler::init(SDL_Renderer* renderer){
    newplayer.init(renderer,100,100);
    newplayer2.init(renderer,200,200);
    newplayer3.init(renderer,300,300);
    newplayer4.init(renderer,400,400);
}
/**
    Update function to call each character update function
*/
void CharacterHandler::update(){
    newplayer.update();
    newplayer2.update();
    newplayer3.update();
    newplayer4.update();

}
/**
    Render function to draw the game object to the screen
*/
void CharacterHandler::render(){
    newplayer.render();
    newplayer2.render();
    newplayer3.render();
    newplayer4.render();
}

void CharacterHandler::keyEventHandler(SDL_Event event){
    newplayer.keyEventListener(event);
    newplayer2.keyEventListener(event);
    newplayer3.keyEventListener(event);
    newplayer4.keyEventListener(event);
}
