#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <string>
#include "../components/ComponentManager.h"
#include <typeinfo>
/**
    Abstract Game Object class that will hold all components of a game object
*/
class GameObject
{
    public:
        // Component Manager
        Manager manager;
        Entity& entityHandler;
        // Constructor
        GameObject():entityHandler(this->manager.addEntity()){};
        // Add and Get Components
        template <typename T,typename... Args> void addComponent(Args... args){
            entityHandler.addComponent<T>(args...);

        }
        template <typename T> T& getComponent(){
            entityHandler.getComponent<T>();
        }
        //virtual void update() = 0;
        //virtual void render() = 0;
};

#endif // GAMEOBJECT_H
