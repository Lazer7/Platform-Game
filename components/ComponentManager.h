#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentID(){
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept
{
    static ComponentID typeID = getComponentID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*,maxComponents>;

class Component{
    public:
        Entity* entity;

        virtual void init(){}
        virtual void update(){};
        virtual void draw(){};
        virtual~Component(){};
};

class Entity{
    private:
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;
        ComponentArray componentArray;
        ComponentBitSet componentBitSet;
    public:
        Entity()=default;
        Entity(Entity& other){
            other.components = std::move(components);
        };
        Entity& operator=(Entity& other){
            other.components = std::move(components);
            return other;
        };

        void update()
        {
            for(auto& c: components) c->update();
        }
        void draw(){
            for(auto& c: components) c->draw();
        }
        bool isActive(){ return active;}
        void destroy(){ active=false;}
        template <typename T> bool hasComponent()const
        {
            return componentBitSet[getComponentID<T>()];
        }
        template <typename T, typename... TArgs>
        T& addComponent(TArgs&&... mArgs){
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity=this;
            std::unique_ptr<Component> uPtr{c};
            components.emplace_back(std::move(uPtr));

            componentArray[getComponentID<T>()]= c;
            componentBitSet[getComponentID<T>()]=true;

            c->init();
            return *c;
        }
        template<typename T> T& getComponent(){
            auto ptr(componentArray[getComponentID<T>()]);
            return *static_cast<T*>(ptr);
        }

};

class Manager{
    private:
        std::vector<std::unique_ptr<Entity>> entities;
    public:
        Manager()=default;
        Manager(Manager& other){
            other.entities = std::move(entities);
        };
        Manager& operator=(Manager& other){
            other.entities = std::move(entities);
            return other;
        };

        void update(){
            for(auto& e : entities) e->update();
        }
        void draw(){
            for(auto& e: entities) e->draw();
        }
        void destroyEntities(){
            entities.erase(std::remove_if(std::begin(entities),std::end(entities),
            [](const std::unique_ptr<Entity>&mEntity){
                return true;
            }), std::end(entities));
        }
        void refresh(){
            entities.erase(std::remove_if(std::begin(entities),std::end(entities),
            [](const std::unique_ptr<Entity>&mEntity){
                return !mEntity->isActive();
            }), std::end(entities));
        }
        Entity& addEntity(){
            Entity* e = new Entity();
            std::unique_ptr<Entity> uPtr{e};
            entities.emplace_back(std::move(uPtr));
            return *e;
        }
};
#endif
