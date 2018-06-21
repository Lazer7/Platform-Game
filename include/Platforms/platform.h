#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <string>
#include "../components/Components.h"
#include "GameObject.h"
using namespace std;

class Platform : public GameObject{
    private:
        // Platform Image
        const char* platformType;
        // Platform Starting Location
        int x,y;
    public:
        // Default Constructor
        Platform()=default;
        // Copy Constructor
        Platform(const Platform& other){
            this->init(other.platformType,other.x,other.y);
        };
        Platform& operator=(const Platform& other){
            this->init(other.platformType,other.x,other.y);
            return *this;
        }
        // Default DeConstructor
        ~Platform()=default;
        // Initializes the GameObject
        void init(const char* platformType, int x, int y){
            this->x=x;
            this->y=y;
            this->platformType=platformType;
            this->addComponent<TransformComponent>(x,y,150,75);
            this->addComponent<SpriteRenderer>(platformType);
            this->addComponent<ColliderComponent>("Platform");
            this->getComponent<TransformComponent>().velocity.x =-1;
        }
        // Renders the Game Object onto the renderer
        void render(){
            GameObject::render();
        }
        // Updates the Game Object
        void update(){
            GameObject::update();
        }




};



#endif  //PLATFORM_H
