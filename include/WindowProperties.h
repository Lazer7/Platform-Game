#ifndef WINDOWPROPERTIES_H
#define WINDOWPROPERTIES_H
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <SDL.h>
class WindowValue{
    public:
        int width;
        int height;
        int FPS;
        float Wscale,Hscale;
        bool fullscreen;
};

class WindowProperties
{
    public:
        static bool init();
        static void setWindowProperties(WindowValue);
        static void setWindowProperties(int,int,float,float,int,bool);
        static void setDefaultWindowProperties();
        static void resizeWindowEvent(SDL_Event event,SDL_Window*);
        static const std::string title;
        static WindowValue windowValue;
        static float getWidthDisposition();
        static float getHeightDisposition();

};

#endif // WINDOWPROPERTIES_H
