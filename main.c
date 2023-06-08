#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.h"

SDL_Color create_sdl_color(uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 255;
    return color;
}
int main(int argc, char **argv)
{
    GameWindow *window = create_game_window("lol no", DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
    if (window == NULL)
    {
        return EXIT_FAILURE;
    }
    Game game;
    init_game(&game, window);

    uint64_t now = SDL_GetPerformanceCounter();
    uint64_t last = 0;
    float deltaTime = 0.f;
    SDL_Event e;
    int quit = 0;
    while (quit == 0)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = 1;
        }
        last = now;
        now = SDL_GetPerformanceCounter();
        deltaTime = ((float)(now - last) * 1000.f / (float)SDL_GetPerformanceFrequency());
        update_game(&game, deltaTime);

        game_window_begin_drawing(window, create_sdl_color(255, 255, 255));
        // insert any drawing here
        for (uint32_t i = 0; i < BLOCK_COUNT_TOTAL; i++)
        {
            if (valid_block(&game.blocks[i]))
            {
                draw_block(&game.blocks[i], window->renderer);
            }
        }
        draw_ball(&game.ball, window->renderer);
        game_window_end_drawing(window);
    }
    free_game_window(window);
    return EXIT_SUCCESS;
}
