#include "Media.h"
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
Media::Media()
{
    //ctor
}

Media::~Media()
{
    //dtor
    Mix_FreeMusic(Music);
    Music=NULL;
    Mix_Quit();
}

bool Media:: init(const char* musicFile){
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    Mix_QuerySpec(&audio_rate, &audio_format, &audio_channels);
    return loadMusic(musicFile);
}
bool Media::loadMusic(const char* musicFile){
    //Load music
    Music = Mix_LoadMUS( musicFile );
    if( Music == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    return true;
}
void Media::play(){
    if(Mix_PlayingMusic()==0){
        Mix_PlayMusic(Music, -1);
    }
}
void Media::pause(){
    Mix_PauseMusic();
}
void Media::resume(){
    Mix_ResumeMusic();
}
void Media::stop(){
    Mix_HaltMusic();
}
