#include "game.h"

void init_game(Game *game, GameWindow *window)
{
    game->window = window;

    const float block_width = DEFAULT_WINDOW_WIDTH / BLOCK_COUNT_HORIZONTAL;
    const float block_height = DEFAULT_WINDOW_HEIGHT / BLOCK_COUNT_VERTICAL * (BLOCK_SIZE_RATIO);

    for (uint32_t x = 0; x < BLOCK_COUNT_HORIZONTAL; x++)
    {
        for (uint32_t y = 0; y < BLOCK_COUNT_VERTICAL; y++)
        {
            init_block(
                &game->blocks[x + y * BLOCK_COUNT_HORIZONTAL],
                rect(
                    vec2((float)x * block_width, (float)y * block_height),
                    vec2(block_width, block_height)),
                rand() % EPBNC_MAX);
        }
    }

    init_ball(&game->ball, vec2(DEFAULT_WINDOW_WIDTH / 2.f, DEFAULT_WINDOW_HEIGHT / 2.f), 15.f);
}

void update_game(Game *game, float delta)
{
    game->ball.collision_rect.position = vec2_add(game->ball.collision_rect.position, vec2_mul_f(game->ball.velocity, delta));
    if (game->ball.collision_rect.position.x < 0)
    {
        game->ball.collision_rect.position.x = 0;
        game->ball.velocity.x *= -1.f;
    }
    if (game->ball.collision_rect.position.y < 0)
    {
        game->ball.collision_rect.position.y = 0;
        game->ball.velocity.y *= -1.f;
    }

    if (game->ball.collision_rect.position.x > DEFAULT_WINDOW_WIDTH)
    {
        game->ball.collision_rect.position.x = DEFAULT_WINDOW_WIDTH;
        game->ball.velocity.x *= -1.f;
    }
    if (game->ball.collision_rect.position.y > DEFAULT_WINDOW_HEIGHT)
    {
        game->ball.collision_rect.position.y = DEFAULT_WINDOW_HEIGHT;
        game->ball.velocity.y *= -1.f;
    }
}