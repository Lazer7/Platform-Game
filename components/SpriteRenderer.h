#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "Components.h"
#include "SDL_image.h"
#include "SDL.h"


class SpriteRenderer : public Component
{
    private:
        // Height and Width of image
        int height,width;
        // Position of the image on the frame
        TransformComponent* transformer;
        SDL_Rect srcRect, destRect;
        SDL_Texture* spriteSheetTexture;
        SDL_Renderer* renderer;
        // Animation variables
        bool animated = false;
        int frames = 0;
        int speed = 100;

    public:
        // Overloaded Constructors
        SpriteRenderer(SDL_Renderer* renderer){
            this->renderer = renderer;
        };
        SpriteRenderer(SDL_Renderer* renderer,const char* spriteSheet,int width, int height){
            this->renderer = renderer;
            setTexture(spriteSheet);
            this->width=width;
            this->height=height;
        };
        SpriteRenderer(SDL_Renderer* renderer,const char* spriteSheet,int width, int height, int frames, int speed){
            this->renderer = renderer;
            setTexture(spriteSheet);
            this->width=width;
            this->height=height;
            animated = true;
            this->frames = frames;
            speed = speed;
        };
        void setTexture(const char* spriteSheet){
            SDL_Surface* tempSurface = IMG_Load(spriteSheet);
            spriteSheetTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
            SDL_FreeSurface(tempSurface);
        }
        void init() override
        {
           transformer = &entity->getComponent<TransformComponent>();

            srcRect.x = srcRect.y = 0;
            srcRect.w = destRect.w = width;
            srcRect.h = destRect.h = height;
        }
        void update() override
        {
            if(animated)
            {
                srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks()/speed)%frames);
            }
            destRect.x = (int)transformer->position.x;
            destRect.y = (int)transformer->position.y;
        }
        void draw() override
        {
            SDL_RenderCopy(renderer,spriteSheetTexture,&srcRect,&destRect);
        }

};

#endif // SPRITERENDERER_H
