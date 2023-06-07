#include <stdio.h>
#include <SDL2/SDL.h>
#include "window.h"

int main(int argc, char **argv)
{
    BG_GameWindow *window = create_game_window(800, 600);

    SDL_FillRect(window->screen, NULL, SDL_MapRGB(window->screen->format, 0xff, 0xff, 0xff));
    SDL_UpdateWindowSurface(window->window);
    SDL_Event e;
    int quit = 0;
    while (quit == 0)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = 1;
        }
    }
    return EXIT_SUCCESS;
}
