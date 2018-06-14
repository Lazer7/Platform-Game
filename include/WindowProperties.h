#ifndef WINDOWPROPERTIES_H
#define WINDOWPROPERTIES_H
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class WindowValue{
    public:
        int width;
        int height;
        int FPS;
        float scale;
        bool fullscreen;
};

class WindowProperties
{
    public:
        static bool init();
        static void setWindowProperties(WindowValue);
        static void setWindowProperties(int,int,int,int,bool);
        static void setDefaultWindowProperties();
        static const std::string title;
        static WindowValue windowValue;

};

#endif // WINDOWPROPERTIES_H
