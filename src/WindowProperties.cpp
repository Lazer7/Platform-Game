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
    remove("data/WindowScreen.dat");
    std::ofstream out("data/WindowScreen.dat",std::ios::binary);
    out.write((char*) &scale, sizeof(scale));
    int attributes = GetFileAttributes("data/WindowScreen.dat");
    if((attributes & FILE_ATTRIBUTE_HIDDEN)==0){
        SetFileAttributes("data/WindowScreen.dat", attributes + FILE_ATTRIBUTE_HIDDEN);
    }
    windowValue=scale;
    out.close();
}
void WindowProperties::setWindowProperties(int w,int h,float Ws,float Hs, int FPS, bool fullscreen){
    WindowValue scale;
    scale.fullscreen=fullscreen;
    scale.width=w;
    scale.height=h;
    scale.Wscale = Ws;
    scale.Hscale = Hs;
    scale.FPS = FPS;
    setWindowProperties(scale);
}
void WindowProperties::setDefaultWindowProperties(){
    WindowValue scale;
    scale.fullscreen=false;
    scale.width=1000;
    scale.height=600;
    scale.Wscale = 1;
    scale.Hscale = 1;
    scale.FPS = 60;
    setWindowProperties(scale);
}

void WindowProperties::resizeWindowEvent(SDL_Event event,SDL_Window* window){
    if(event.type == SDL_WINDOWEVENT){
        switch(event.window.event){
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            if(event.window.data1 < 1000 || event.window.data2 < 600){
                WindowProperties::setDefaultWindowProperties();
                SDL_SetWindowSize(window,1000,600);
            }
            else{
                float wScale = (float)(event.window.data1) /1000.0f;
                float hScale = (float)(event.window.data2) /600.0f;
                WindowProperties::setWindowProperties(event.window.data1,
                                                     event.window.data2,
                                                     wScale,
                                                     hScale,
                                                     WindowProperties::windowValue.FPS,
                                                     WindowProperties::windowValue.fullscreen);

            }
        break;
        }
    }
}
float WindowProperties::getWidthDisposition(){
    return (float)WindowProperties::windowValue.width/1000.0f;
}
float WindowProperties::getHeightDisposition(){
    return (float)WindowProperties::windowValue.height/600.0f;
}
