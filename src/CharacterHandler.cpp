#include "CharacterHandler.h"
/**
    Initializes all Character Assets in the Game
    TODO:: Refactor to place all characters in a vector
    @param renderer the rendering engine to place all game objects
*/
void CharacterHandler::init(SDL_Renderer* renderer){
    newplayer.init(renderer,200,475);
    wall.addComponent<TransformComponent>(500,350,75,75);
    wall.addComponent<SpriteRenderer>(renderer,"assets/up.bmp",900,900);
    wall.addComponent<ColliderComponent>("Wall");
}
/**
    Update function to call each character update function
*/
void CharacterHandler::update(){
    newplayer.update();
    wall.update();
    newplayer.onCollisionDetection(wall.getComponent<ColliderComponent>());
}
/**
    Render function to draw the game object to the screen
*/
void CharacterHandler::render(){
    newplayer.render();
    wall.render();
}

void CharacterHandler::keyEventHandler(SDL_Event event){
    newplayer.keyEventListener(event);
}
