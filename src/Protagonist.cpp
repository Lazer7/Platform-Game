#include "Protagonist.h"
#include <stdio.h>
Protagonist::Protagonist(char* spriteSheet, SDL_Renderer* renderer):GameObject(spriteSheet,renderer)
{
    this->xpos = 0;
    this->ypos = 250;
}

Protagonist::Protagonist(char* spriteSheet, SDL_Renderer* renderer, int xpos, int ypos):GameObject(spriteSheet,renderer)
{
    this->xpos = xpos;
    this->ypos = ypos;
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

}

void Protagonist:: render()
{
    SDL_RenderCopy(this->renderer, this->objTexture,NULL,&this->destRect);
}

void Protagonist::handleEvent(SDL_Event event){
    switch(event.key.keysym.sym)
    {
        case SDLK_a:
            this->xpos-=10;
            break;
        case SDLK_d:
            this->xpos+=10;
            break;

    }

}


