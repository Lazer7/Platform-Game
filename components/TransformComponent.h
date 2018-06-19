
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include "../include/Vector2D.h"
#include <iostream>
#include "../include/WindowProperties.h"
#include <math.h>
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
        position.x = x + WindowProperties::getWidthDisposition();
        position.y = y + WindowProperties::getHeightDisposition();
        height = 32;
        width = 32;
    }
    TransformComponent(float x, float y, int width, int height)
    {
        position.x = x;
        position.y = y;
        this->height = height;
        this->width = width;
    }
    int getWidth(){
        return width*WindowProperties::windowValue.Wscale;
    }
    int getHeight(){
        return height*WindowProperties::windowValue.Hscale;
    }
    int x(){return ceil((float)position.x * WindowProperties::getWidthDisposition());}
    int y(){return ceil((float)position.y * WindowProperties::getHeightDisposition());}
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

