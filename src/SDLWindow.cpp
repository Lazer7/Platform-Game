#include "SDLWindow.h"

SDL_Texture* background;
SDL_Texture* playerTex;
SDL_Rect scrR, destR;
int cnt=0;
SDLWindow::SDLWindow(int width,int height,std::string title,bool fullscreen)
{

    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 )
    {
        this->isRunning=true;
        //Create window
        this->window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreen );
        this->renderer = SDL_CreateRenderer(this->window, -1 ,0);
        if( this->window != NULL && this->renderer != NULL )
        {
            //Get window surface
            this->screen_surface = SDL_GetWindowSurface( this->window );
            SDL_SetRenderDrawColor(this->renderer,255,255,255,255);
        }
        else
        {
            printf( "Something could not be created! SDL_Error: %s\n", SDL_GetError() );
            this->isRunning = false;
        }
        background = TextureManager::loadTexture("assets/test.bmp",this->renderer);
        playerTex  = TextureManager::loadTexture("assets/up.bmp",this->renderer);

        Protagonist x("assets/down.bmp",this->renderer);
    }
    else
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        this->isRunning = false;
    }
}
SDLWindow::~SDLWindow()
{

    //Destroy window
    SDL_DestroyWindow( this->window );
    this->window = NULL;

    SDL_DestroyRenderer(this->renderer);

    //Quit SDL subsystems
    SDL_Quit();
    //dtor
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
    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, background, NULL, NULL);
    SDL_RenderCopy(this->renderer, playerTex, NULL, &destR);
    SDL_RenderPresent(this->renderer);
}
void SDLWindow:: update(){
    cnt++;
    destR.h = 32;
    destR.w = 32;
    destR.x = cnt;
    destR.y = cnt;
}


void SDLWindow:: capFrameRate(int FPS, int frameStart){
    int frameTime = SDL_GetTicks() - frameStart;

    printf("Frame Started %d\n", frameStart );
    if((1000/FPS)> frameTime){
        SDL_Delay((1000/FPS) - frameTime);
    }
}

