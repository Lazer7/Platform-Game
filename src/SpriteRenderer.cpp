#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(SDL_Texture* spriteSheet,int animationFrames,int width, int height, int x, int y):animationFrames(animationFrames)
{
    this->spriteSheetTexture= spriteSheet;
    this->width=width;
    this->height=height;
    this->x=x;
    this->y=y;
    splitSprite();
    //ctor
}

SpriteRenderer::~SpriteRenderer()
{
    SDL_DestroyTexture(this->spriteSheetTexture);
    this->spriteSheetTexture=NULL;
    delete spriteClips;
    //dtor
}
void SpriteRenderer::splitSprite(){
    int xpos = 0;
    int ypos = y;
    for(int i=0; i<animationFrames; i++){
        spriteClips[i].x = xpos;
        spriteClips[i].y = ypos;
        spriteClips[i].w = width;
        spriteClips[i].h = height;
        xpos+=x;
        //ypos+=y;
    }
}
SDL_Rect* SpriteRenderer::getClip(){
    if(SDL_RectEmpty(&spriteClips[currentFrame])){
        splitSprite();
    }
    return &this->spriteClips[currentFrame];
}
void SpriteRenderer::nextFrame(){
    if(currentFrame<animationFrames-1){
        currentFrame++;
    }
    else{resetFrame();}
}

void SpriteRenderer::resetFrame(){
    currentFrame=0;
}
