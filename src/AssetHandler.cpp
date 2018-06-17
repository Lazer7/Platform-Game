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
    // COLLISION REFERENCE
//    wall.addComponent<TransformComponent>(500,350,75,75);
//    wall.addComponent<SpriteRenderer>(renderer,"assets/up.bmp",900,900);
//    wall.addComponent<ColliderComponent>("Wall");
    music.play();
}
/**
    Update function to call each asset's update function
*/
void AssetHandler::update(){
    addPlatform();
    newplayer.update();
    list<Platform>::iterator it;
    for(it= platforms.begin(); it!= platforms.end(); ++it){
        it->update();
    }
    // COLLISION REFERENCE
//  wall.update();
//  newplayer.onCollisionDetection(wall.getComponent<ColliderComponent>());
}
/**
    Render function to draw the game object to the screen
*/
//int counter = 0;
void AssetHandler::render(){
    background.render();
    newplayer.render();
    list<Platform>::iterator it;
    for(it= platforms.begin(); it!= platforms.end(); ++it){
        it->render();
    }
    // COLLISION REFERENCE
//    wall.render();
//    counter++;
//    if(counter == 100){
//        newplayer.~PlayableCharacter();
//    }
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
    if((SDL_GetTicks() - frameStart)>1000){
        platforms.push_back(PlatformFactory::Create(renderer,"Grass"));
        frameStart=SDL_GetTicks();
    }
}
