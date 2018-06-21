#ifndef PLATFORMFACTORY_H
#define PLATFORMFACTORY_H
#include <string>
#include <iostream>
#include <ctime>
#include "Platforms/platform.h"
#include "Platforms/platformTypes.h"
#include "SDL.h"
#include "WindowProperties.h"
using namespace std;

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
            platform.init(PlatformTypes::platforms[rand()%5].c_str(),WindowProperties::WindowWidth,jumpHeights[rand()%4]);
            //cout << WindowProperties::windowValue.width << endl;
            //cout << platform.getComponent<TransformComponent>().position << endl;
            return platform;
        }

};

#endif //PLATFORMFACTORY
