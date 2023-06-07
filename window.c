#include "window.h"


void free_game_window(BG_GameWindow *window)
{
    SDL_DestroyWindow(window->window);
    SDL_FreeSurface(window->screen);
    free(window);
}

BG_GameWindow *create_game_window(int width, int height)
{
    BG_GameWindow *game = malloc(sizeof(BG_GameWindow));
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        free(game);
        return NULL;
    }
    game->window = SDL_CreateWindow("your mom", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (game->window == NULL)
    {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        free(game);
        return NULL;
    }
    game->screen = SDL_GetWindowSurface(game->window);
    return game;
}