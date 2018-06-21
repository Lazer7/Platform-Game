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
        static Platform Create(std::string type){
            int jumpHeights[4] = {150, 250, 350, 450};
            srand(time(NULL));
            PlatformTypes::setPlatformType(type);
            Platform platform;
            platform.init(PlatformTypes::platforms[rand()%5].c_str(),WindowProperties::windowValue.width,jumpHeights[rand()%4]);
            return platform;
        }

};

#endif //PLATFORMFACTORY
