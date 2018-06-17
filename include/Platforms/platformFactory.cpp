#include "Platforms/platformFactory.h"


Platform PlatformFactory::Create(SDL_Renderer* renderer, std::string type){
            PlatformTypes::setPlatformType(type);
            Platform platform;
            std::cout << PlatformTypes::platforms[2] << std::endl;
            //platform->init(renderer, PlatformTypes::platforms[2].c_str(),500,500);
            return platform;
}
