
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

    int height;
    int width;

    TransformComponent()
    {
        position.x=0.0f;
        position.y=0.0f;
        height = 32;
        width = 32;
    }
    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
        height = 32;
        width = 32;
    }
    TransformComponent(float x, float y, int height, int width)
    {
        position.x = x;
        position.y = y;
        this->height = height;
        this->width = width;
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

