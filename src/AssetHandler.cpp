#include "AssetHandler.h"
#include "Platforms/platformTypes.h"
#include "Platforms/platform.h"
#include "Platforms/platformFactory.h"
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
std::list<Platform> platforms;

void AssetHandler::init(){
    this->frameStart = SDL_GetTicks();

    music.init("audio/Blessing.mp3");
    background.init("assets/backgrounds/gamebackground.jpg");
    newplayer.init(800,475);
    music.play();
}
/**
    Update function to call each asset's update function
*/
void AssetHandler::update(){
    addPlatform();
    list<Platform>::iterator it;
    for(it= platforms.begin(); it!= platforms.end(); ++it){
        it->update();
    }
    newplayer.update();
    for(it= platforms.begin(); it!= platforms.end(); ++it){
        newplayer.onCollisionDetection(it->getComponent<ColliderComponent>());
    }
}
/**
    Render function to draw the game object to the screen
*/

void AssetHandler::render(){
    background.render();
    list<Platform>::iterator it;
    for(it= platforms.begin(); it!= platforms.end(); ++it){
        it->render();
    }
    newplayer.render();
}
/**
    Handles Key Events for game objects
*/
void AssetHandler::keyEventHandler(){
    background.update();
    newplayer.keyEventListener();
}
/**
    Create Platform Assets every second
*/
void AssetHandler::addPlatform(){
    if((SDL_GetTicks() - frameStart)>3000){
        platforms.push_back(PlatformFactory::Create("Grass"));
        frameStart=SDL_GetTicks();
    }
}
