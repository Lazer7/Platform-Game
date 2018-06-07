#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include "TextureManager.h"
#include "Components.h"
#include "SDL.h"
class SpriteRenderer : public Component
{
    private:
        int height,width;
        TransformComponent* transformer;
        SDL_Rect srcRect, destRect;
        SDL_Texture* spriteSheetTexture;

        bool animated = false;
        int frames = 0;
        int speed = 100;

    public:
        SpriteRenderer() = default;
        SpriteRenderer(const char* spriteSheet,int width, int height){
            spriteSheetTexture = TextureManager::loadTexture(spriteSheet);
            this->width=width;
            this->height=height;
        };
        SpriteRenderer(const char* spriteSheet,int width, int height, int frames, int speed){
            spriteSheetTexture = TextureManager::loadTexture(spriteSheet);
            this->width=width;
            this->height=height;
            animated = true;
            this->frames = frames;
            speed = speed;
        };
        void setTexture(const char* spriteSheet){
            spriteSheetTexture = TextureManager::loadTexture(spriteSheet);
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
            TextureManager::Draw(spriteSheetTexture,srcRect,destRect);
        }

};

#endif // SPRITERENDERER_H
