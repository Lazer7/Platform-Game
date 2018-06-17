#include "Platforms/platformTypes.h"
std::vector<std::string> PlatformTypes::platforms;
/**
    Gets all platform types from a specific folder
*/
void PlatformTypes::setPlatformType(std::string type){
    std::string path = "./assets/platforms/" + type;
    DIR *dp;
    struct dirent *dirp;
    dp = opendir( path.c_str());
    while((dirp = readdir(dp))){
        std::string filepath = path+"/" + dirp->d_name;
        PlatformTypes::platforms.push_back(filepath);
        // std:: cout << dirp->d_name << std::endl;
        std:: cout << filepath << std::endl;
    }
}
