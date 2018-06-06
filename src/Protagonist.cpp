#include "Protagonist.h"

Protagonist::Protagonist(char* spriteSheet, SDL_Renderer* renderer):GameObject(spriteSheet,renderer)
{
    this->xpos = 0;
    this->ypos = 250;
    this->maxHeight = this->ypos-100;
    this->currentHeight= ypos;
    animatedRightSprite = new SpriteRenderer(this->objTexture,3,30,32,32,32);
    animatedLeftSprite = new SpriteRenderer(this->objTexture,3,30,32,32,64);
    animatedIdleSprite = new SpriteRenderer(this->objTexture,3,30,32,32,0);
}

Protagonist::Protagonist(char* spriteSheet, SDL_Renderer* renderer, int xpos, int ypos):GameObject(spriteSheet,renderer)
{
    this->xpos = xpos;
    this->ypos = ypos;
    this->maxHeight = this->ypos-50;
    this->currentHeight= ypos;
}

Protagonist::~Protagonist()
{
    SDL_DestroyTexture( this->objTexture );
    this->objTexture = NULL;
    animatedIdleSprite->~SpriteRenderer();
    animatedLeftSprite->~SpriteRenderer();
    animatedRightSprite->~SpriteRenderer();
}
void Protagonist:: update(){
    destRect.w = 50;
    destRect.h = 50;
    destRect.x = xpos;
    destRect.y = ypos;
    if(this->isJumpingUp && (ypos>maxHeight)) ypos-=5;
    else if(this->isJumpingDown && (ypos!=currentHeight)){ ypos+=5;isJumpingUp=false;}
    else{isJumpingDown=false;}
    if(isMovingRight){
        this->xpos-=10;
    }
    if(isMovingLeft){
        this->xpos+=10;
    }

}

void Protagonist:: render()
{
    SDL_Rect* currentClip= animatedIdleSprite->getClip();
    if(isMovingRight){
        currentClip = animatedRightSprite->getClip();
        animatedRightSprite->nextFrame();
    }
    else if(isMovingLeft){
        currentClip = animatedLeftSprite->getClip();
        animatedLeftSprite->nextFrame();
    }

    SDL_RenderCopy(this->renderer, this->objTexture,currentClip,&this->destRect);
}

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
