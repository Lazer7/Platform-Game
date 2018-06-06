#include "GameObject.h"
/**
    GameObject Constructor
    @param spriteSheet the game object image
    @param renderer the current renderer the object will be render to
*/
GameObject::GameObject(char* spriteSheet, SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->objTexture = TextureManager::loadTexture(spriteSheet,this->renderer);
}

GameObject::~GameObject()
{
    SDL_DestroyTexture( this->objTexture );
    this->objTexture = NULL;
    //dtor
}
