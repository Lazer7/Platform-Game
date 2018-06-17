#ifndef PLATFORMTYPES_H
#define PLATFORMTYPES_H
#include <string>
#include <iostream>
#include <vector>
#include <dirent.h>

class PlatformTypes{
    public:
        static void setPlatformType(std::string type);
        // Holds all the platform images locations
        static std::vector<std::string> platforms;

};


#endif //PLATFORMTYPES_H
