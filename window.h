#pragma once

#include <stdlib.h>
#include <SDL2/SDL.h>

/// @brief Struct that holds information about SDL2 window 
typedef struct 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} GameWindow;

/// @brief Frees memory used by window and SDL2
/// @param window Window handle
void free_game_window(GameWindow *window);

/// @brief Clears the canvas and sets window into drawing mode
/// @param window Window handle
/// @param clear_color Canvas clear color
void game_window_begin_drawing(GameWindow *window, SDL_Color clear_color);

/// @brief Sets window into normal mode and renders all of the changes
/// @param window Window handle
void game_window_end_drawing(GameWindow *window);

/// @brief Inits SDL2 and creates a new window handle
/// @param window_title 
/// @param width 
/// @param height 
/// @return Window handle or NULL if failed to create
GameWindow *create_game_window(const char *window_title, int width, int height);