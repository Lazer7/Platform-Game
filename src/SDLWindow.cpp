#include "SDLWindow.h"

/**
    SDLWindow Initialization: Sets the attributes of the game window
    @param width of the screen
    @param height of the screen
    @param title of the screen
    @param fullscreen is a boolean to make the game fullscreen or not
*/
SDLWindow::SDLWindow() {
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 && WindowProperties::init()){
        // Set flag to notify the system is running
        this->isRunning=true;
        // Creates the window
        WindowProperties::window = SDL_CreateWindow( WindowProperties::title.c_str(),
                                                     SDL_WINDOWPOS_UNDEFINED,
                                                     SDL_WINDOWPOS_UNDEFINED,
                                                     WindowProperties::windowValue.width,
                                                     WindowProperties::windowValue.height,
                                                     SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
        SDL_Surface *surface;     // Declare an SDL_Surface to be filled in with pixel data from an image file
        surface = IMG_Load("assets/logo.png");
        SDL_SetWindowIcon(WindowProperties::window, surface);
        SDL_FreeSurface(surface);
        WindowProperties::renderer = SDL_CreateRenderer(WindowProperties::window, -1 ,0);
        if( WindowProperties::window != NULL && WindowProperties::renderer != NULL){
            // Set background to white
            SDL_SetRenderDrawColor(WindowProperties::renderer,255,255,255,255);
        }
        else{
            // Error has occurred stop systems
            printf( "Something could not be created! SDL_Error: %s\n", SDL_GetError() );
            this->isRunning = false;
        }
        assetHandler.init();
    }
    else{
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        this->isRunning = false;
    }
}
SDLWindow::~SDLWindow() {
    //Destroy window
    SDL_DestroyRenderer( WindowProperties::renderer );
    SDL_DestroyWindow( WindowProperties::window );
    WindowProperties::window = NULL;
    WindowProperties::renderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

/**
    Handles any input or outputs that occurs in the window
*/
void SDLWindow:: handleEvents() {
    SDL_PollEvent(&WindowProperties::event);
    switch(WindowProperties::event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
        default:
            WindowProperties::resizeWindowEvent();
            assetHandler.keyEventHandler();
            break;
    }
}
/**
    Renders game assets to the screen
*/
void SDLWindow:: render() {
    SDL_RenderClear(WindowProperties::renderer);
    assetHandler.render();
    SDL_RenderPresent(WindowProperties::renderer);
}
/**
    Updates the game assets
*/
void SDLWindow:: update() {
    assetHandler.update();
}
int cnt=0;
/**
    Caps the Game Frame Rate
    @param FPS the frame per second
    @param frameStart the starting frame time
*/
void SDLWindow:: capFrameRate(int frameStart) {
    int FPS = WindowProperties::windowValue.FPS;
    int frameTime = SDL_GetTicks() - frameStart;

    //printf("Frame Started %d\n", cnt );
    cnt++;
    if((1000/FPS)> frameTime){
        SDL_Delay((1000/FPS) - frameTime);
    }
}

