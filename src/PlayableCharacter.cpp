#include "PlayableCharacter.h"
// TODO:: JUMP MECHANIC DOESN'T SCALE WITH WINDOW HEIGHT RESIZE
int orignal_height;
bool notOnPlatform;
/**
    Initalizes the Player Game Object at specified location
    @param renderer the game renderer the player object will be rendered on
    @param x the horizontal (x) position starting point
    @param y the vertical (y) position starting point
*/
void PlayableCharacter::init(int x, int y){
    notOnPlatform = true;
    this->addComponent<TransformComponent>(x,y,100,100);
    this->addComponent<SpriteRenderer>("assets/characters/main_character_right.png",32,32,3,100);
    this->addComponent<ColliderComponent>("Player");
    orignal_height=y;
    MaxHeight = getComponent<TransformComponent>().y()-150;
    currentHeight = getComponent<TransformComponent>().y();
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
    int y = getComponent<TransformComponent>().y(); // Get Absolute y position
    if(notOnPlatform){
        currentHeight = (int) orignal_height* WindowProperties::windowValue.Hscale;
    }
    if(this->isJumpingUp && (y>MaxHeight)){
        getComponent<TransformComponent>().velocity.y=-10;
    }
    else if((y<=currentHeight)){
        getComponent<TransformComponent>().velocity.y=10;
        isJumpingUp=false;
    }
    else{
        isJumpingDown=false;
        getComponent<TransformComponent>().velocity.y=0;
        MaxHeight = y-(150*WindowProperties::windowValue.Hscale);
        currentHeight = y;
    }
    // Moves player left or right based on what key is being pressed
    if(isMovingRight && ( x + playerWidth) <= WindowProperties::windowValue.width){
        getComponent<TransformComponent>().velocity.x=10;
        getComponent<SpriteRenderer>().setTexture("assets/characters/main_character_right.png");
    }
    else if(isMovingLeft&&x>=0 ){
        getComponent<TransformComponent>().velocity.x=-10;
        getComponent<SpriteRenderer>().setTexture("assets/characters/main_character_left.png");
    }
    else{
        getComponent<TransformComponent>().velocity.x=0;
    }
}
/**
    Listens to keyboard events and updates the player position
*/
void PlayableCharacter::keyEventListener(){
    // Checks for Key Presses
    if(WindowProperties::event.type == SDL_KEYDOWN){
        switch(WindowProperties::event.key.keysym.sym){
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
    if(WindowProperties::event.type == SDL_KEYUP){
        switch(WindowProperties::event.key.keysym.sym){
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
    Detects Player collision with certain objectsad
*/
void PlayableCharacter::onCollisionDetection(ColliderComponent collider){
    std::string name = collider.tag;
    if(getComponent<ColliderComponent>().collision(collider)&& name.compare("Platform")==0){
        int platformHeight = collider.collider.y;
        int playerHeight = getComponent<TransformComponent>().y()+ getComponent<TransformComponent>().getHeight()- (10*WindowProperties::windowValue.Hscale);
        if(playerHeight<=platformHeight && !isJumpingUp){
            MaxHeight = platformHeight-(150*WindowProperties::windowValue.Hscale)-getComponent<TransformComponent>().getHeight();
            currentHeight = platformHeight-getComponent<TransformComponent>().getHeight();
            isJumpingDown=false;
            getComponent<TransformComponent>().velocity.y=0;
            notOnPlatform = false;
        }
    }
    else{
        notOnPlatform = true;
    }
}
