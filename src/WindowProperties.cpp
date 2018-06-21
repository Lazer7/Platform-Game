#include "WindowProperties.h"

// Static window properties
const std::string WindowProperties::title="Platform Game";
WindowValue WindowProperties::windowValue;
SDL_Window* WindowProperties::window = NULL;
SDL_Surface* WindowProperties::screen_surface = NULL;
SDL_Renderer* WindowProperties::renderer = NULL;
SDL_Event WindowProperties::event;
/**
    Initialize Window settings from the WindowScreen.dat file
*/
bool WindowProperties::init() {
    WindowValue scale;
    std::ifstream data("data/WindowScreen.dat",std::ios::binary);
    // checks if file exist
    if(data.is_open()) {
        data.read((char *) &scale,sizeof(scale));
        windowValue=scale;
        return true;
    }
    // If not initialize with default data
    else {
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
/**
    Set Window Properties with scale values
*/
void WindowProperties::setWindowProperties(WindowValue scale) {
    remove("data/WindowScreen.dat");
    std::ofstream out("data/WindowScreen.dat",std::ios::binary);
    out.write((char*) &scale, sizeof(scale));
    int attributes = GetFileAttributes("data/WindowScreen.dat");
    if((attributes & FILE_ATTRIBUTE_HIDDEN)==0) {
        SetFileAttributes("data/WindowScreen.dat", attributes + FILE_ATTRIBUTE_HIDDEN);
    }
    windowValue=scale;
    out.close();
}
/**
    Set Window Properties with scale values
*/
void WindowProperties::setWindowProperties(int w,int h,float Ws,float Hs, int FPS, bool fullscreen) {
    WindowValue scale;
    scale.fullscreen=fullscreen;
    scale.width=w;
    scale.height=h;
    scale.Wscale = Ws;
    scale.Hscale = Hs;
    scale.FPS = FPS;
    setWindowProperties(scale);
}
/**
    Reset Window Properties
*/
void WindowProperties::setDefaultWindowProperties() {
    WindowValue scale;
    scale.fullscreen=false;
    scale.width=1000;
    scale.height=600;
    scale.Wscale = 1;
    scale.Hscale = 1;
    scale.FPS = 60;
    setWindowProperties(scale);
}
/**
    Change Window setting based on window event actions
*/
void WindowProperties::resizeWindowEvent() {
    if(event.type == SDL_WINDOWEVENT){
        switch(event.window.event){
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            if(event.window.data1 < 1000 || event.window.data2 < 600) {
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
/**
    Get the window's width distortion based on the orignal size
*/
float WindowProperties::getWidthDisposition() {
    return (float)WindowProperties::windowValue.width/1000.0f;
}
/**
    Get the window's height distortion based on the orignal size
*/
float WindowProperties::getHeightDisposition() {
    return (float)WindowProperties::windowValue.height/600.0f;
}
