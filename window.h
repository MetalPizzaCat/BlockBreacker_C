#pragma once

#include <stdlib.h>
#include <SDL2/SDL.h>
struct GameWindow
{
    SDL_Window *window;
    SDL_Surface *screen;
};
typedef struct GameWindow BG_GameWindow;

void free_game_window(BG_GameWindow *window);
BG_GameWindow *create_game_window(int width, int height);