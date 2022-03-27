#ifndef TETRIS_INCLUDED_EVENT
#define TETRIS_INCLUDED_EVENT
#include <SDL2/SDL.h>
#include <stdbool.h>

void handleEvents(SDL_Event event,
                  bool *loop);

#endif
