#include "Protagonist.h"
/**
    Playable Character Constructor
    @param spriteSheet the character's image sprite sheet
    @param renderer the current renderer the character will be render to
*/
Protagonist::Protagonist(char* spriteSheet, SDL_Renderer* renderer):GameObject(spriteSheet,renderer)
{
    // Character positions
    this->xpos = 0;
    this->ypos = 250;
    // Character Jumping positions
    this->maxHeight = this->ypos-100;
    this->currentHeight= ypos;
    // Character animations
    animatedRightSprite = new SpriteRenderer(this->objTexture,3,30,32,32,32);
    animatedLeftSprite = new SpriteRenderer(this->objTexture,3,30,32,32,64);
    animatedIdleSprite = new SpriteRenderer(this->objTexture,3,30,32,32,0);
}
/**
    Playable Character Constructor
    @param spriteSheet the character's image sprite sheet
    @param renderer the current renderer the character will be render to
    @param xpos the player's starting x position
    @param ypos the player's starting y position
*/
Protagonist::Protagonist(char* spriteSheet, SDL_Renderer* renderer, int xpos, int ypos):GameObject(spriteSheet,renderer)
{
    // Character positions
    this->xpos = xpos;
    this->ypos = ypos;
    // Character Jumping positions
    this->maxHeight = this->ypos-50;
    this->currentHeight= ypos;
    // Character animations
    animatedRightSprite = new SpriteRenderer(this->objTexture,3,30,32,32,32);
    animatedLeftSprite = new SpriteRenderer(this->objTexture,3,30,32,32,64);
    animatedIdleSprite = new SpriteRenderer(this->objTexture,3,30,32,32,0);
}

Protagonist::~Protagonist()
{
    animatedIdleSprite->~SpriteRenderer();
    animatedLeftSprite->~SpriteRenderer();
    animatedRightSprite->~SpriteRenderer();
}
/**
    Protagonist Update Function to update position and stats
*/
void Protagonist:: update(){
    // Set the next destination location of the image on the window
    destRect.w = 50;
    destRect.h = 50;
    destRect.x = xpos;
    destRect.y = ypos;
    // Check if the user is jumping
    if(this->isJumpingUp && (ypos>maxHeight)) ypos-=5;
    else if(this->isJumpingDown && (ypos!=currentHeight)){ ypos+=5;isJumpingUp=false;}
    else{isJumpingDown=false;}
    // Check the direction of the user movement
    if(isMovingRight){
        this->xpos-=10;
    }
    if(isMovingLeft){
        this->xpos+=10;
    }
}
/**
    Render's SDL assets onto the screen
*/
void Protagonist:: render()
{
    // Gets the current animation frame
    SDL_Rect* currentClip= animatedIdleSprite->getClip();
    if(isMovingRight){
        currentClip = animatedRightSprite->getClip();
        animatedRightSprite->nextFrame();
    }
    else if(isMovingLeft){
        currentClip = animatedLeftSprite->getClip();
        animatedLeftSprite->nextFrame();
    }
    // Displays the current animation frame
    SDL_RenderCopy(this->renderer, this->objTexture,currentClip,&this->destRect);
}
/**
    Handles KeyDown events on the keyboard
    @param event the SDL Input/Output Object
*/
void Protagonist::handleKeyDownEvent(SDL_Event event){
    switch(event.key.keysym.sym)
    {
        case SDLK_a:
            isMovingLeft=false;
            isMovingRight=true;
            animatedLeftSprite->resetFrame();
            break;
        case SDLK_d:
            isMovingRight=false;
            isMovingLeft=true;
            animatedRightSprite->resetFrame();
            break;
        case SDLK_SPACE:
            isJumpingUp=true;
            isJumpingDown=true;
            break;
    }
}
/**
    Handles KeyUp events on the keyboard
    @param event the SDL Input/Output Object
*/
void Protagonist::handleKeyUpEvent(SDL_Event event){
    switch(event.key.keysym.sym)
    {
        case SDLK_a:
            isMovingRight=false;
        break;
        case SDLK_d:
            isMovingLeft=false;
        break;
    }
}
