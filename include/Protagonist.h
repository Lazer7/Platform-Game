#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <GameObject.h>


class Protagonist : public GameObject
{
    public:
        Protagonist(char* spriteSheet, SDL_Renderer* renderer);
        virtual ~Protagonist();
        void update();
        void render();
    protected:

    private:
};

#endif // PROTAGONIST_H
