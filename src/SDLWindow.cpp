#include "SDLWindow.h"


/**
    SDLWindow Initialization: Sets the attributes of the game window
    @param width of the screen
    @param height of the screen
    @param title of the screen
    @param fullscreen is a boolean to make the game fullscreen or not
*/
SDLWindow::SDLWindow(int width,int height,std::string title,bool fullscreen)
{
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 )
    {
        // Set flag to notify the system is running
        this->isRunning=true;
        // Creates the window
        this->window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreen );
        this->renderer = SDL_CreateRenderer(this->window, -1 ,0);
        if( this->window != NULL && this->renderer != NULL )
        {
            // Set background to white
            SDL_SetRenderDrawColor(this->renderer,255,255,255,255);
        }
        else
        {
            // Error has occurred stop systems
            printf( "Something could not be created! SDL_Error: %s\n", SDL_GetError() );
            this->isRunning = false;
        }
        background.init(this->renderer,"assets/gamebackground.jpg");
        characterHandler.init(this->renderer);


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
    SDL_DestroyRenderer( this->renderer );
    SDL_DestroyWindow( this->window );
    this->window = NULL;
    this->renderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

/**
    Handles any input or outputs that occurs in the window
*/
void SDLWindow:: handleEvents(){
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
        default:
            characterHandler.keyEventHandler(event);
            break;
    }
}
/**
    Renders game assets to the screen
*/
void SDLWindow:: render()
{
    SDL_RenderClear(this->renderer);
    background.render();
    characterHandler.render();
    SDL_RenderPresent(this->renderer);
}
/**
    Updates the game assets
*/
void SDLWindow:: update(){
    background.update();
    characterHandler.update();
}
int cnt=0;
/**
    Caps the Game Frame Rate
    @param FPS the frame per second
    @param frameStart the starting frame time
*/
void SDLWindow:: capFrameRate(int FPS, int frameStart){
    int frameTime = SDL_GetTicks() - frameStart;

    printf("Frame Started %d\n", cnt );
    cnt++;
    if((1000/FPS)> frameTime){
        SDL_Delay((1000/FPS) - frameTime);
    }
}

