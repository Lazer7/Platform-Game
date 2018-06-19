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
        if(strcmp(dirp->d_name,"..")!=0 && strcmp(dirp->d_name,".")!=0 ){
            PlatformTypes::platforms.push_back(filepath);
        }
    }
}
