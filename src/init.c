#include "../header/init.h"

bool init() 
{
    bool flag = true;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) 
    {
        printf("Unable to initialize SDL: %s\n", 
               SDL_GetError());

        flag = false;
    }

    if (TTF_Init() == -1) 
    {
        printf("TTF_Init: %s\n", 
               TTF_GetError());

        flag = false;
    }

    if (Mix_OpenAudio(44100, 
                      MIX_DEFAULT_FORMAT, 
                      2, 
                      2048) == -1) 
    {
        printf("Mix_OpenAudio: %s\n", 
                Mix_GetError());

        flag = false;
    }

    return flag;
}

