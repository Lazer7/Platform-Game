
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include "../include/Vector2D.h"
#include <iostream>
#include "../include/WindowProperties.h"
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
    float scale;
    TransformComponent()
    {
        position.x=0.0f;
        position.y=0.0f;
        scale = WindowProperties::windowValue.scale;
        height = 32*scale;
        width = 32*scale;
    }
    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
        scale = WindowProperties::windowValue.scale;
        height = 32*scale;
        width = 32*scale;
    }
    TransformComponent(float x, float y, int height, int width)
    {
        position.x = x;
        position.y = y;
        scale = WindowProperties::windowValue.scale;
        this->height = height*scale;
        this->width = width*scale;
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

