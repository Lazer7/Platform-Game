#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <GameObject.h>


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
        bool isJumpingUp =false;
        bool isJumpingDown =false;
        bool isMovingRight = false;
        bool isMovingLeft = false;
        int maxHeight;
        int currentHeight;
        SDL_Rect destRect, sourceRect;
};

#endif // PROTAGONIST_H
