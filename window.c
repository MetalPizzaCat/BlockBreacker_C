#include "window.h"

void free_game_window(GameWindow *window)
{
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->window);
    free(window);
    SDL_Quit();
}

GameWindow *create_game_window(const char *window_title, int width, int height)
{
    GameWindow *game = malloc(sizeof(GameWindow));
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        free(game);
        return NULL;
    }
    game->window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (game->window == NULL)
    {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        free(game);
        return NULL;
    }
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (game->renderer == NULL)
    {
        fprintf(stderr, "Unable to create renderer! SDL_Error: %s\n", SDL_GetError());
        free(game);
        return NULL;
    }
    return game;
}

void game_window_begin_drawing(GameWindow *window, SDL_Color clear_color)
{
    SDL_SetRenderDrawColor(window->renderer, clear_color.r, clear_color.g, clear_color.b, 255);
    SDL_RenderClear(window->renderer);
}
void game_window_end_drawing(GameWindow *window)
{
    SDL_RenderPresent(window->renderer);
}