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
        static const int WindowHeight;
        static const int WindowWidth;
        static const std::string title;
        static SDL_Window* window;
        static SDL_Surface* screen_surface;
        static WindowValue windowValue;
        static SDL_Renderer* renderer;
        static SDL_Event event;


        static bool init();
        static void setWindowProperties(WindowValue);
        static void setWindowProperties(int,int,float,float,int,bool);
        static void setDefaultWindowProperties();
        static void resizeWindowEvent();
        static float getWidthDisposition();
        static float getHeightDisposition();

};

#endif // WINDOWPROPERTIES_H
