#include "WindowProperties.h"
const std::string WindowProperties::title="Platform Game";
WindowValue WindowProperties::windowValue;
bool WindowProperties::init(){
    WindowValue scale;
    std::ifstream data("data/WindowScreen.dat",std::ios::binary);
    if(data.is_open()){
        data.read((char *) &scale,sizeof(scale));
        windowValue=scale;
        return true;
    }
    else{
        setDefaultWindowProperties();
        std::ifstream data("data/WindowScreen.dat",std::ios::binary);
        if(data.is_open()){
            data.read((char *) &scale,sizeof(scale));
        }
        return true;

    }
    data.close();
    return false;
}
void WindowProperties::setWindowProperties(WindowValue scale){
    std::ofstream out("data/WindowScreen.dat",std::ios::binary);
    out.write((char*) &scale, sizeof(scale));
    int attributes = GetFileAttributes("data/WindowScreen.dat");
    if((attributes & FILE_ATTRIBUTE_HIDDEN)==0){
        SetFileAttributes("data/WindowScreen.dat", attributes + FILE_ATTRIBUTE_HIDDEN);
    }
    windowValue=scale;
    out.close();
}
void WindowProperties::setWindowProperties(int w,int h,int s, int FPS, bool fullscreen){
    WindowValue scale;
    scale.fullscreen=fullscreen;
    scale.width=w;
    scale.height=h;
    scale.scale = s;
    scale.FPS = FPS;
    setWindowProperties(scale);
}
void WindowProperties::setDefaultWindowProperties(){
    WindowValue scale;
    scale.fullscreen=false;
    scale.width=1000;
    scale.height=600;
    scale.scale = 1;
    scale.FPS = 60;
    setWindowProperties(scale);
}
