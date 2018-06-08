#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <string>
#include "../components/ComponentManager.h"
#include <typeinfo>

class GameObject
{
    public:
        GameObject();
        Manager manager;
        Entity& entityHandler;
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
