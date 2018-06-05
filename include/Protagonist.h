#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <GameObject.h>
#include <SDL_thread.h>

class Protagonist : public GameObject
{
    public:
        Protagonist(char* spriteSheet, SDL_Renderer* renderer);
        Protagonist(char* spriteSheet, SDL_Renderer* renderer, int xpos, int ypos);
        virtual ~Protagonist();
        void update();
        void render();
        void handleEvent(SDL_Event);
    protected:

    private:
        int xpos;
        int ypos;
        SDL_Rect destRect, sourceRect;
};

#endif // PROTAGONIST_H
