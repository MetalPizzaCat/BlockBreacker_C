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

typedef enum
{
    AS_Game,
    AS_Editor
} AppState;

int main(int argc, char **argv)
{
    AppState state = AS_Editor;
    // This only works if BLOCK_COUNT_TOTAL < 64 since each bit in the number is a block
    // i'm mainly using this because implementing file reading in c sucks :3
    // but this will have to be changed if fancier ideas appear(like special blocks and such)
    uint64_t map = 0;
    for (int i = 0; i < argc; ++i)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
        if (!strcmp(argv[i], "--ed"))
        {
            state = AS_Editor;
            if (i + 1 < argc)
            {
                char *ptr;
                printf("making map: %lu from %s \n", strtoul(argv[i + 1], 0, 10), argv[i + 1]);
                map = strtoul(argv[i + 1], 0, 10);
            }
            else
            {
                printf("No map code provided, creating default map...");
            }
        }
    }
    GameWindow *window = create_game_window("lol no", DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
    if (window == NULL)
    {
        return EXIT_FAILURE;
    }
    Game game;
    // (uint64_t)-1 wraps around to becoming max value of unsigned 64 bit integer
    init_game(&game, window, (map ? map : (uint64_t)-1));

    const float block_width = DEFAULT_WINDOW_WIDTH / BLOCK_COUNT_HORIZONTAL;
    const float block_height = DEFAULT_WINDOW_HEIGHT / BLOCK_COUNT_VERTICAL * (BLOCK_SIZE_RATIO);

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
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                uint32_t x = (e.button.x / (uint32_t)block_width);
                uint32_t y = (e.button.y / (uint32_t)block_height);
                uint32_t block_id = x + y * BLOCK_COUNT_HORIZONTAL;
                if (block_id < BLOCK_COUNT_TOTAL)
                {
                    if (e.button.button == SDL_BUTTON_LEFT)
                    {
                        game.blocks[block_id].state = EBS_Normal;
                    }
                    else if (e.button.button == SDL_BUTTON_RIGHT)
                    {
                        game.blocks[block_id].state = EBS_Destroyed;
                    }
                }
            }
        }
        last = now;
        now = SDL_GetPerformanceCounter();
        deltaTime = ((float)(now - last) * 1000.f / (float)SDL_GetPerformanceFrequency());
        if (state == AS_Game)
        {
            update_game(&game, deltaTime);
        }
        else
        {
        }

        game_window_begin_drawing(window, create_sdl_color(255, 255, 255));
        // insert any drawing here
        for (uint32_t i = 0; i < BLOCK_COUNT_TOTAL; i++)
        {
            if (valid_block(&game.blocks[i]))
            {
                draw_block(&game.blocks[i], window->renderer);
            }
        }
        if (state == AS_Game)
        {
            draw_ball(&game.ball, window->renderer);
        }
        game_window_end_drawing(window);
    }
    uint64_t out = 0;
    if (state == AS_Editor)
    {
        for (uint64_t i = 0; i < BLOCK_COUNT_TOTAL; i++)
        {
            out |= ((uint64_t)(game.blocks[i].state == EBS_Normal)) << (BLOCK_COUNT_TOTAL - i);
        }
    }
    free_game_window(window);
    printf("Your map %lu\n", out);
    return EXIT_SUCCESS;
}
