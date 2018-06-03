#include "GameObject.h"

GameObject::GameObject(char* spriteSheet, SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->objTexture = TextureManager::loadTexture(spriteSheet,this->renderer);
}

GameObject::~GameObject()
{
    //dtor
}
