#ifndef MAP_H
#define MAP_H
#include "SDL.h"
#include "SDL_image.h"
#include "WindowProperties.h"
class Map
{
    public:
        Map()=default;
        void init(const char* spriteMap);
        void setTexture(const char* spriteMap);
        void render();
        void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
        void update();
        virtual ~Map();

    protected:

    private:
        bool isScroll=false;
        int scrollOffset=0;
        SDL_Texture* spriteSheetTexture;
};

#endif // MAP_H
