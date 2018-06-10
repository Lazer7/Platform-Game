#include "PlayableCharacter.h"
#include <iostream>
using namespace std;
void PlayableCharacter::init(SDL_Renderer* renderer,int x, int y){
    this->addComponent<TransformComponent>(x,y,100,100);
    this->addComponent<SpriteRenderer>(renderer,"assets/main_character_right.png",32,32,3,100);
    this->addComponent<ColliderComponent>("Player");
    MaxHeight = y-100;
    currentHeight=y;
}
void PlayableCharacter::render(){
    GameObject::render();
}

void PlayableCharacter::update(){
    GameObject::update();
    int height = getComponent<TransformComponent>().position.y;
    if(this->isJumpingUp && (height>MaxHeight)) getComponent<TransformComponent>().velocity.y=-3;
    else if(this->isJumpingDown && (height!=currentHeight)){ getComponent<TransformComponent>().velocity.y=3;isJumpingUp=false;}
    else{isJumpingDown=false;getComponent<TransformComponent>().velocity.y=0;}

    if(isMovingRight){
        getComponent<TransformComponent>().velocity.x=3;
        getComponent<SpriteRenderer>().setTexture("assets/main_character_right.png");

    }
    else if(isMovingLeft){
        getComponent<TransformComponent>().velocity.x=-3;
        getComponent<SpriteRenderer>().setTexture("assets/main_character_left.png");
    }
    else{
        getComponent<TransformComponent>().velocity.x=0;
    }
}

void PlayableCharacter::keyEventListener(SDL_Event event){
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym)
        {
            case SDLK_a:
                isMovingLeft=true;
            break;
            case SDLK_d:
                isMovingRight=true;
            break;
            case SDLK_SPACE:
                isJumpingUp=true;
                isJumpingDown=true;
            break;

        }
    }
    if(event.type == SDL_KEYUP){
        switch(event.key.keysym.sym)
        {
            case SDLK_a:
                isMovingLeft=false;
            break;
            case SDLK_d:
                isMovingRight=false;
            break;
        }
    }
}
void PlayableCharacter::onCollisionDetection(ColliderComponent collider){
    if(getComponent<ColliderComponent>().collision(collider)){
        cout << "I've BEEN HIT" << endl;
    }
}
