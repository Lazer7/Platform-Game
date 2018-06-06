#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <GameObject.h>
#include <SpriteRenderer.h>

class Protagonist : public GameObject
{
    public:
        Protagonist(char* spriteSheet, SDL_Renderer* renderer);
        Protagonist(char* spriteSheet, SDL_Renderer* renderer, int xpos, int ypos);
        virtual ~Protagonist();
        void update();
        void render();
        void handleKeyDownEvent(SDL_Event);
        void handleKeyUpEvent(SDL_Event);
    protected:

    private:
        int xpos;
        int ypos;
        bool isJumpingUp =false;
        bool isJumpingDown =false;
        bool isMovingRight = false;
        bool isMovingLeft = false;
        int currentFrame=0;
        int animationFrames =3;
        int maxHeight;
        int currentHeight;
        SDL_Rect destRect;
        SpriteRenderer* animatedLeftSprite;
        SpriteRenderer* animatedRightSprite;
        SpriteRenderer* animatedIdleSprite;
};

#endif // PROTAGONIST_H
