#ifndef TETRIS_INCLUDED_WINDOW
#define TETRIS_INCLUDED_WINDOW

#include <stdbool.h>
#include <SDL2/SDL.h>

#define WIDTH_SCREEN    740
#define HEIGHT_SCREEN   740

SDL_Window *create_window(SDL_Window *window,
                   const char* name_window, 
                   int x_position_screen, 
                   int y_position_screen, 
                   int width_screen, 
                   int height_screen, 
                   int flags);

#endif
