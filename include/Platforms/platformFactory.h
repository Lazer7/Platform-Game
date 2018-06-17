#ifndef PLATFORMFACTORY_H
#define PLATFORMFACTORY_H
#include <string>
#include <iostream>
#include <ctime>
#include "Platforms/platform.h"
#include "Platforms/platformTypes.h"
#include "SDL.h"
#include "WindowProperties.h"

class PlatformFactory{
    public:
        /**
            Platform Creater that creates a random platform and return it as a game object
        */
        static Platform Create(SDL_Renderer* renderer, std::string type){
             int jumpHeights[3] = {150, 250, 350};
            srand(time(NULL));
            PlatformTypes::setPlatformType(type);
            Platform platform;
            std::cout << PlatformTypes::platforms[2] << std::endl;
            platform.init(renderer, PlatformTypes::platforms[2].c_str(),WindowProperties::windowValue.width,jumpHeights[rand()%3]);
            return platform;
        }

};

#endif //PLATFORMFACTORY
