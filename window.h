#pragma once

#include <stdlib.h>
#include <SDL2/SDL.h>
struct GameWindow
{
    SDL_Window *window;
    SDL_Renderer *renderer;
};
typedef struct GameWindow BG_GameWindow;

void free_game_window(BG_GameWindow *window);
void game_window_begin_drawing(BG_GameWindow *window, uint8_t red, uint8_t green, uint8_t blue);
void game_window_end_drawing(BG_GameWindow *window);
BG_GameWindow *create_game_window(const char *window_title, int width, int height);