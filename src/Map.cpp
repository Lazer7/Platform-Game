#include "Map.h"
#include <iostream>
using namespace std;
/**
    Map deconstructor
*/
Map::~Map(){
    //dtor
    SDL_DestroyTexture(this->spriteSheetTexture);
    spriteSheetTexture=NULL;
}
/**
    Initalizes the map with image
*/
void Map:: init(const char* spriteMap){
    setTexture(spriteMap);
}
/**
    Sets Map image
*/
void Map::setTexture(const char* spriteMap){
    SDL_Surface* tempSurface = IMG_Load(spriteMap);
    spriteSheetTexture = SDL_CreateTextureFromSurface(WindowProperties::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}
/**
    Draws 2 map images onto the renderer
*/
void Map::render(){
    render( scrollOffset, 0 );
    render( scrollOffset + WindowProperties::windowValue.width, 0 );
}

/**
    Draws a map onto the renderer at a given position
*/
void Map::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip ){
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, WindowProperties::windowValue.width, WindowProperties::windowValue.height };

	//Set clip rendering dimensions
	if( clip != NULL ){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//Render to screen
	SDL_RenderCopyEx( WindowProperties::renderer, spriteSheetTexture, clip, &renderQuad, angle, center, flip );

}
/**
    Updates the Scrolling of the map in the background
*/
void Map::update(){
    //Scroll background
    --scrollOffset;
    if( scrollOffset <  -WindowProperties::windowValue.width){
        scrollOffset = 0;
    }
}
