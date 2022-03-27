#include "../header/event.h"
#include <SDL2/SDL.h>

void handleEvents(SDL_Event event,
                  bool *loop)
{
    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {

            case SDL_QUIT:
            {
                *loop = false; 
            }break;

            case SDL_KEYDOWN: 
            {
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    *loop = false;
                }
            }
        }
    }
}
