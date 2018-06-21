#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H
#include "GameObject.h"
#include "../components/Components.h"
#include "WindowProperties.h"
#include <iostream>
using namespace std;

class PlayableCharacter : public GameObject
{
    public:
        PlayableCharacter()= default;
        virtual ~PlayableCharacter()=default;
        void init(int,int);
        void update();
        void render();
        void keyEventListener();
        void onCollisionDetection(ColliderComponent);
    protected:

    private:
        int MaxHeight, currentHeight;
        bool isMovingRight=false, isMovingLeft=false, isJumpingUp=false, isJumpingDown=false;
};

#endif // PLAYABLECHARACTER_H
