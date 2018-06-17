#include "PlayableCharacter.h"
// TODO:: JUMP MECHANIC DOESN'T SCALE WITH WINDOW HEIGHT RESIZE

/**
    Initalizes the Player Game Object at specified location
    @param renderer the game renderer the player object will be rendered on
    @param x the horizontal (x) position starting point
    @param y the vertical (y) position starting point
*/
void PlayableCharacter::init(SDL_Renderer* renderer,int x, int y){
    this->addComponent<TransformComponent>(x,y,100,100);
    this->addComponent<SpriteRenderer>(renderer,"assets/characters/main_character_right.png",32,32,3,100);
    this->addComponent<ColliderComponent>("Player");
    MaxHeight = y-150;
    currentHeight = y;
}
/**
    Draws the game object to the screen
*/
void PlayableCharacter::render(){
    GameObject::render();
}
/**
    Updates Player's position
*/
void PlayableCharacter::update(){
    GameObject::update();
    // Checks what is the current jumping status of player
    int playerWidth = getComponent<TransformComponent>().getWidth();
    int x = getComponent<TransformComponent>().x(); // Get relative x position
    int y = getComponent<TransformComponent>().position.y; // Get Absolute y position
    if(this->isJumpingUp && (y>MaxHeight)){
        getComponent<TransformComponent>().velocity.y=-3;
    }
    else if(this->isJumpingDown && (y!=currentHeight)){
        getComponent<TransformComponent>().velocity.y=3;
        isJumpingUp=false;
    }
    else{
        isJumpingDown=false;getComponent<TransformComponent>().velocity.y=0;
    }
    // Moves player left or right based on what key is being pressed
    if(isMovingRight && ( x + playerWidth) <= WindowProperties::windowValue.width){
        getComponent<TransformComponent>().velocity.x=5;
        getComponent<SpriteRenderer>().setTexture("assets/characters/main_character_right.png");
    }
    else if(isMovingLeft&&x>=0 ){
        getComponent<TransformComponent>().velocity.x=-5;
        getComponent<SpriteRenderer>().setTexture("assets/characters/main_character_left.png");
    }
    else{
        getComponent<TransformComponent>().velocity.x=0;
    }
}
/**
    Listens to keyboard events and updates the player position
*/
void PlayableCharacter::keyEventListener(SDL_Event event){
    // Checks for Key Presses
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){
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
    // Checks for Key Releases
    if(event.type == SDL_KEYUP){
        switch(event.key.keysym.sym){
            case SDLK_a:
                isMovingLeft=false;
            break;
            case SDLK_d:
                isMovingRight=false;
            break;
        }
    }
}
/**
    Detects Player collision with certain objects
*/
void PlayableCharacter::onCollisionDetection(ColliderComponent collider){
    if(getComponent<ColliderComponent>().collision(collider)){
        cout << "I've BEEN HIT" << endl;
    }
}
