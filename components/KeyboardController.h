
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include "../include/SDLWindow.h"
#include "ComponentManager.h"
#include "Components.h"
class KeyboardController : public Component{
    public:
        TransformComponent *transformer;

        void init() override
        {
            transformer = &entity->getComponent<TransformComponent>();
        }
        void update() override
        {
            if(Game::event.type == SDL_KEYDOWN)
            {

            }

        }


};

#endif
