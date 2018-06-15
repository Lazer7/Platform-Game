#include "AssetHandler.h"
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
    @param renderer the rendering engine to place all game objects
*/

void AssetHandler::init(SDL_Renderer* renderer){
    music.init("audio/Blessing.mp3");
    background.init(renderer,"assets/gamebackground2.png");
    newplayer.init(renderer,800,475);
    wall.addComponent<TransformComponent>(500,350,75,75);
    wall.addComponent<SpriteRenderer>(renderer,"assets/up.bmp",900,900);
    wall.addComponent<ColliderComponent>("Wall");
    music.play();
}
/**
    Update function to call each asset's update function
*/
void AssetHandler::update(){
    newplayer.update();
    wall.update();
    newplayer.onCollisionDetection(wall.getComponent<ColliderComponent>());
}
/**
    Render function to draw the game object to the screen
*/
//int counter = 0;
void AssetHandler::render(){
    background.render();
    newplayer.render();
    wall.render();
//    counter++;
//    if(counter == 100){
//        newplayer.~PlayableCharacter();
//    }
}

void AssetHandler::keyEventHandler(SDL_Event event){
    background.update();
    newplayer.keyEventListener(event);
}
