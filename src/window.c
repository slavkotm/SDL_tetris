#include "../header/window.h"

SDL_Window *create_window(SDL_Window *window,
                   const char* name_window, 
                   int x_position_screen, 
                   int y_position_screen, 
                   int width_screen, 
                   int height_screen, 
                   int flags)
{
    window = SDL_CreateWindow(name_window, 
                              x_position_screen, 
                              y_position_screen, 
                              width_screen, 
                              height_screen, 
                              flags);

    if (window == NULL) 
    {
        printf("don't create window...");
    }

    return window;
}
