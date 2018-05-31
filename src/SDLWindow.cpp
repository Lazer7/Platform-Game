#include "SDLWindow.h"

SDLWindow::SDLWindow(int width, int height, std::string title)
{
    //ctor
    this->screen_width = width;
    this->screen_height = height;
    this->title=title;
}

SDLWindow::~SDLWindow()
{
    //Deallocate surface
    SDL_FreeSurface( this->picture );
    this->picture = NULL;

    //Destroy window
    SDL_DestroyWindow( this->window );
    this->window = NULL;

    SDL_DestroyRenderer(this->renderer);

    //Quit SDL subsystems
    SDL_Quit();
    //dtor
}
bool SDLWindow:: init(){

    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 )
    {
        this->isRunning=true;
        //Create window
        this->window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->screen_width, this->screen_height, SDL_WINDOW_SHOWN );
        if( this->window != NULL )
        {
            //Get window surface
            this->screen_surface = SDL_GetWindowSurface( this->window );
        }
        else
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            this->isRunning = false;
        }
        this->renderer = SDL_CreateRenderer(this->window, -1 ,0);
        if(this->renderer != NULL){
            SDL_SetRenderDrawColor(this->renderer,255,255,255,255);
            printf("Render has been created");
        }
        else{
            this->isRunning = false;
        }
    }
    else
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        this->isRunning = false;
    }
}
void SDLWindow::loadMedia(std::string path)
{
    //Load splash image
    this->picture = SDL_LoadBMP(path.c_str());
    if( this->picture == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "image", SDL_GetError() );
        this->isRunning = false;
    }
}

void SDLWindow:: handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
    case SDL_QUIT:
        isRunning=false;
        break;
        default:
        break;
    }
}

void SDLWindow:: render()
{
    //SDL_RenderClear(this->renderer);
    //SDL_RenderPresent(this->renderer);
    SDL_BlitSurface( this->picture, NULL, this->screen_surface, NULL );
    SDL_UpdateWindowSurface( this->window );
}
void SDLWindow:: update(){
    printf("FOREVER LOOP");
}


void SDLWindow:: delay(int milliseconds){
    SDL_Delay(milliseconds);
}

