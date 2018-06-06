#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include "TextureManager.h"
#include "SDL.h"
#include "SDL_image.h"

class SpriteRenderer
{
    public:
        SpriteRenderer(SDL_Texture* spriteSheet,int animationFrames, int width, int height, int x, int y);
        virtual ~SpriteRenderer();
        SDL_Rect* getClip(int);
    private:
        void splitSprite();
        const int animationFrames;
        int x,y,width,height;
        SDL_Rect spriteClips[];
        SDL_Texture* spriteSheetTexture;
};

#endif // SPRITERENDERER_H
