
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include "../include/Vector2D.h"
#include <iostream>
using namespace std;
/**
    Holds Game Object Locations on the screen
*/
class TransformComponent : public Component
{

public:
    Vector2D position;
    Vector2D velocity;


    TransformComponent()
    {
        position.x=0.0f;
        position.y=0.0f;
    }
    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
    void init() override
    {
        velocity.x=0;
        velocity.y=0;
    }
    void update() override
    {
        position.x += velocity.x;
        position.y += velocity.y;
    }


};
#endif

