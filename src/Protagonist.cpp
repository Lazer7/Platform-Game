#include "Protagonist.h"
#include <stdio.h>
Protagonist::Protagonist(char* spriteSheet, SDL_Renderer* renderer):GameObject(spriteSheet,renderer)
{
    this->xpos = 0;
    this->ypos = 250;
    this->maxHeight = this->ypos-100;
    this->currentHeight= ypos;
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
}
void Protagonist:: update(){
    destRect.w = 64;
    destRect.h = 64;
    destRect.x = xpos;
    destRect.y = ypos;
    if(this->isJumpingUp && (ypos>maxHeight)) ypos-=2;
    else if(this->isJumpingDown && (ypos!=currentHeight)){ ypos+=2;isJumpingUp=false;}
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
    SDL_RenderCopy(this->renderer, this->objTexture,NULL,&this->destRect);
}

void Protagonist::handleKeyDownEvent(SDL_Event event){
    switch(event.key.keysym.sym)
    {
        case SDLK_a:
            isMovingRight=true;
            break;
        case SDLK_d:
            isMovingLeft=true;
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
