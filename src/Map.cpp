#include "Map.h"
#include <iostream>
using namespace std;

Map::~Map()
{
    //dtor
}
void Map:: init(SDL_Renderer* renderer,const char* spriteMap)
{
    //ctor
    this->renderer = renderer;
    setTexture(spriteMap);
}

void Map::setTexture(const char* spriteMap){
    SDL_Surface* tempSurface = IMG_Load(spriteMap);
    spriteSheetTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    width = WindowProperties::windowValue.width;
    height = WindowProperties::windowValue.height;
    SDL_FreeSurface(tempSurface);
}

void Map::render(){
    render( scrollOffset, 0 );
    render( scrollOffset + width, 0 );
}


void Map::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip ){
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, width, height };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( renderer, spriteSheetTexture, clip, &renderQuad, angle, center, flip );

}
void Map::update(){
    //Scroll background
    --scrollOffset;
    if( scrollOffset <  -width)
    {
        scrollOffset = 0;
    }
}
