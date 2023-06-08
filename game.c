#include "game.h"

void init_game(Game *game, GameWindow *window, uint64_t map)
{
    game->window = window;

    const float block_width = DEFAULT_WINDOW_WIDTH / BLOCK_COUNT_HORIZONTAL;
    const float block_height = DEFAULT_WINDOW_HEIGHT / BLOCK_COUNT_VERTICAL * (BLOCK_SIZE_RATIO);

    uint64_t mask = 1;
    uint64_t offset = BLOCK_COUNT_TOTAL;
    for (uint64_t y = 0; y < BLOCK_COUNT_VERTICAL; y++)
    {
        for (uint64_t x = 0; x < BLOCK_COUNT_HORIZONTAL; x++)
        {
            init_block(
                &game->blocks[x + y * BLOCK_COUNT_HORIZONTAL],
                rect(
                    vec2((float)x * block_width, (float)y * block_height),
                    vec2(block_width, block_height)),
                rand() % EPBNC_MAX, 1);

            uint64_t key = (map & (mask << offset)) >> offset;
            printf("%lu", key);
            if (!key)
            {
                damage_block(&game->blocks[x + y * BLOCK_COUNT_HORIZONTAL]);
            }
            offset--;
        }
    }
    printf("\n");

    init_ball(&game->ball, vec2(DEFAULT_WINDOW_WIDTH / 2.f, DEFAULT_WINDOW_HEIGHT / 2.f), 5.f);
    init_block(&game->paddle, rect(vec2_add(vec2(DEFAULT_WINDOW_WIDTH / 2.f, DEFAULT_WINDOW_HEIGHT * 0.9f), vec2(10, 10)), vec2(100, 10)), EPBC_LightGray, 0);
}

int game_ball_check_block_collision(Game *game, Block *block)
{
    if (!valid_block(block))
    {
        return 0;
    }
    if (rect_does_intersect(&game->ball.collision_rect, &block->collision_rect))
    {
        // grab the values so we don't have to look at the massive lines
        Vector2 const ball_pos = vec2_add(game->ball.collision_rect.position, vec2_mul_f(game->ball.collision_rect.size, 0.5f));
        Vector2 const *brick_pos = &block->collision_rect.position;
        Vector2 const *brick_size = &block->collision_rect.size;

        // underneath
        if (ball_pos.y >= brick_pos->y + (brick_size->y / 2.f))
        {
            game->ball.velocity.y = -game->ball.default_velocity.y;
        }
        // above
        else if (ball_pos.y <= brick_pos->y + (brick_size->y / 2.f))
        {
            game->ball.velocity.y = game->ball.default_velocity.y;
        }
        // left
        if (ball_pos.x < brick_pos->x - (brick_size->x / 2.f))
        {
            game->ball.velocity.x = -game->ball.default_velocity.x;
        }
        // right
        else if (ball_pos.x > brick_pos->x - (brick_size->x / 2.f))
        {
            game->ball.velocity.x = game->ball.default_velocity.x;
        }
        damage_block(block);
        return 1;
    }
    return 0;
}

void update_game(Game *game, float delta)
{
    game->ball.collision_rect.position = vec2_add(game->ball.collision_rect.position, vec2_mul_f(game->ball.velocity, delta));
    for (uint32_t i = 0; i < BLOCK_COUNT_TOTAL; i++)
    {
        if (game_ball_check_block_collision(game, &game->blocks[i]))
        {
            break;
        }
    }
    game_ball_check_block_collision(game, &game->paddle);
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