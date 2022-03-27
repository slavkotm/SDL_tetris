#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "../header/event.h"
#include "../header/init.h"
#include "../header/window.h"
#include "../header/texture.h"
#include "../header/render.h"

int main(int argc, 
         char **argv) 
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *surface_background_picture = NULL, *surface_text_start = NULL;
    SDL_Texture *texture_backgroud_picture = NULL, *texture_text_START = NULL, *texture_text_EXIT = NULL;
    SDL_Rect source_rectangle, destination_rectangle, rectangle_START, rectangle_EXIT;
    SDL_Event event;
    TTF_Font *font = NULL;
    bool loop = init();
    
    renderer = SDL_CreateRenderer(create_window(window, 
                                                "tetris", 
                                                SDL_WINDOWPOS_CENTERED, 
                                                SDL_WINDOWPOS_CENTERED, 
                                                WIDTH_SCREEN, 
                                                HEIGHT_SCREEN, 
                                                SDL_WINDOW_SHOWN), 
                                                -1, 
                                                0);

    texture_backgroud_picture = create_texture("assets/pictures/front_picture.png", 
                                               surface_background_picture, 
                                               texture_backgroud_picture, 
                                               renderer);

    texture_text_START = create_text_texture("assets/text_fonts/arcade.ttf", 
                                       33, 
                                       surface_text_start,
                                       renderer,
                                       font,
                                       255,
                                       255,
                                       255,
                                       255,
                                       "START",
                                       texture_text_START,
                                       &rectangle_START);

    texture_text_EXIT = create_text_texture("assets/text_fonts/arcade.ttf", 
                                       33, 
                                       surface_text_start,
                                       renderer,
                                       font,
                                       255,
                                       255,
                                       255,
                                       255,
                                       "EXIT",
                                       texture_text_EXIT,
                                       &rectangle_EXIT);

    size_background(&source_rectangle, 
                    &destination_rectangle,  
                    WIDTH_SCREEN, 
                    HEIGHT_SCREEN);

    position_text(&rectangle_START, 
                  WIDTH_SCREEN, 
                  HEIGHT_SCREEN,
                  0,
                  -20);

    position_text(&rectangle_EXIT, 
                  WIDTH_SCREEN, 
                  HEIGHT_SCREEN,
                  0,
                  20);
    
    while(loop)
    {
        handleEvents(event, 
                     &loop);
        SDL_RenderClear(renderer);

        render_background(renderer, 
                          texture_backgroud_picture, 
                          source_rectangle, 
                          destination_rectangle);

        render_text(renderer, 
                    texture_text_START, 
                    rectangle_START); 

        render_text(renderer, 
                    texture_text_EXIT, 
                    rectangle_EXIT); 

        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
