#include <stdio.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "block.h"

int main(int argc, char **argv)
{
    BG_GameWindow *window = create_game_window("lol no", DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
    if (window == NULL)
    {
        return EXIT_FAILURE;
    }
    BG_Block *blocks[BLOCK_COUNT_TOTAL];

    const float block_width = DEFAULT_WINDOW_WIDTH / BLOCK_COUNT_HORIZONTAL;
    const float block_height = DEFAULT_WINDOW_HEIGHT / BLOCK_COUNT_VERTICAL * (BLOCK_SIZE_RATIO);

    for (uint32_t x = 0; x < BLOCK_COUNT_HORIZONTAL; x++)
    {
        for (uint32_t y = 0; y < BLOCK_COUNT_VERTICAL; y++)
        {
            blocks[x + y * BLOCK_COUNT_HORIZONTAL] = create_block((float)x * block_width, (float)y * block_height, block_width, block_height, rand() % EPBNC_MAX);
        }
    }
    SDL_Event e;
    int quit = 0;
    while (quit == 0)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = 1;
        }

        game_window_begin_drawing(window, 255, 255, 255);
        // insert any drawing here
        for (uint32_t i = 0; i < BLOCK_COUNT_TOTAL; i++)
        {
            if (blocks[i] == NULL)
            {
                continue;
            }
            draw_block(blocks[i], window->renderer);
        }
        game_window_end_drawing(window);
    }
    for (uint32_t i = 0; i < BLOCK_COUNT_TOTAL; i++)
    {
        free_block(blocks[i]);
    }
    free(blocks);
    free_game_window(window);
    return EXIT_SUCCESS;
}
