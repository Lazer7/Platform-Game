#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H
#include "GameObject.h"
#include "../components/Components.h"

class PlayableCharacter : public GameObject
{
    public:
        PlayableCharacter()= default;
        virtual ~PlayableCharacter()=default;
        void init(SDL_Renderer*,int,int);
        void update();
        void render();
        void keyEventListener(SDL_Event);
        void onCollisionDetection(ColliderComponent);
    protected:

    private:
        SDL_Event event;
        int MaxHeight, currentHeight;
        bool isMovingRight=false, isMovingLeft=false, isJumpingUp=false, isJumpingDown=false;
};

#endif // PLAYABLECHARACTER_H
