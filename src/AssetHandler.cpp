#include "AssetHandler.h"
#include "Platforms/platformTypes.h"
#include "Platforms/platform.h"
#include "Platforms/platformFactory.h"
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
    @param renderer the rendering engine to place all game objects
*/
std::list<Platform> platforms;

void AssetHandler::init(SDL_Renderer* renderer){
    this->renderer = renderer;
    this->frameStart = SDL_GetTicks();

    music.init("audio/Blessing.mp3");
    background.init(renderer,"assets/backgrounds/gamebackground.jpg");
    newplayer.init(renderer,800,475);
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
void AssetHandler::keyEventHandler(SDL_Event event){
    background.update();
    newplayer.keyEventListener(event);
}
/**
    Create Platform Assets every second
*/
void AssetHandler::addPlatform(){
    if((SDL_GetTicks() - frameStart)>3000){
        platforms.push_back(PlatformFactory::Create(renderer,"Grass"));
        frameStart=SDL_GetTicks();
    }
}
