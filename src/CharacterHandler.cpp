#include "CharacterHandler.h"


void CharacterHandler::init(SDL_Renderer* renderer){
    newPlayer.addComponent<TransformComponent>(250,250);
    newPlayer.addComponent<SpriteRenderer>(renderer,"assets/main_character_left.png",32,32,3,100);
    newPlayer2.addComponent<TransformComponent>(100,100);
    newPlayer2.addComponent<SpriteRenderer>(renderer,"assets/main_character_left.png",32,32,3,100);
}

void CharacterHandler::update(){
    newPlayer.manager.refresh();
    newPlayer2.manager.refresh();
    newPlayer.manager.update();
    newPlayer2.manager.update();
}
void CharacterHandler::render(){
    newPlayer.manager.draw();
    newPlayer2.manager.draw();
}
