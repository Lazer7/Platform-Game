#include "SpriteRenderer.h"
/**
    SpriteRenderer Constructor

    @param spriteSheet the sprite sheet texture to be split and rendered onto the screen
    @param animationFrames the max number of frames for the animation
    @param width the in game width size of the image
    @param height the in game height size of the image
    @param x the image starting x location
    @param y the image starting y location
*/
SpriteRenderer::SpriteRenderer(SDL_Texture* spriteSheet,int animationFrames,int width, int height, int x, int y):animationFrames(animationFrames)
{
    this->spriteSheetTexture= spriteSheet;
    this->width=width;
    this->height=height;
    this->x=x;
    this->y=y;
    splitSprite(); // This splits the texture into different individual images
}

SpriteRenderer::~SpriteRenderer()
{
    SDL_DestroyTexture(this->spriteSheetTexture);
    this->spriteSheetTexture=NULL;
    delete spriteClips;
    //dtor
}

/**
    Splits the image texture into individual images for animation and saves it to SDL_Rect
*/
void SpriteRenderer::splitSprite()
{
    int xpos = 0; // Starting X location on the image texture
    int ypos = y;
    // Cuts each image and saves it to to the SDL_Rect array
    for(int i=0; i<animationFrames; i++)
    {
        spriteClips[i].x = xpos;
        spriteClips[i].y = ypos;
        spriteClips[i].w = width;
        spriteClips[i].h = height;
        xpos+=x;
    }
}
/**
    Returns the current animation frame
    @return an SDL_Rect of the current animation image frame
*/
SDL_Rect* SpriteRenderer::getClip()
{
    // Error Handling: Rerender the animation onto the array if the image wasn't loaded into the SDL_Rect properly
    if(SDL_RectEmpty(&spriteClips[currentFrame]))
    {
        splitSprite();
    }
    return &this->spriteClips[currentFrame];
}
/**
    Function that changes the current animation to the next
*/
void SpriteRenderer::nextFrame()
{
    // Checks if the currentFrame has reached the last frame
    if(currentFrame<animationFrames-1)
    {
        currentFrame++;
    }
    else{
        resetFrame(); // If it has then reset the Frame to the beginning
    }
}
/**
    Resets the Animation Frame to the beginning
*/
void SpriteRenderer::resetFrame()
{
    currentFrame=0;
}
