#include "game.h"

void init_game(Game *game, GameWindow *window, AudioManager *audio, uint64_t map)
{
    game->window = window;
    game->ball_launched = 0;
    game->audio = audio;

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
#if ENABLE_MAP_LOADING
            uint64_t key = (map & (mask << offset)) >> offset;
            printf("%lu", key);
            if (!key)
            {
                damage_block(&game->blocks[x + y * BLOCK_COUNT_HORIZONTAL]);
            }
            offset--;
#endif
        }
    }
    printf("\n");

    game_reset_ball_and_paddle(game);
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
        else if (ball_pos.x < brick_pos->x - (brick_size->x / 2.f))
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
    // if game has not started yet(ball didn't get launched)
    // logic works differently where we just move the ball around
    if (!game->ball_launched)
    {
        game->ball.collision_rect.position = vec2_add(game->paddle.collision_rect.position, vec2(game->paddle.collision_rect.size.x / 2.f, -15.f));
        return;
    }
    game->ball.collision_rect.position = vec2_add(game->ball.collision_rect.position, vec2_mul_f(game->ball.velocity, delta));
    for (uint32_t i = 0; i < BLOCK_COUNT_TOTAL; i++)
    {
        if (game_ball_check_block_collision(game, &game->blocks[i]))
        {
            if (game->audio != NULL)
            {
                play_sound_destruction(game->audio);
            }
            if(is_game_finished(game))
            {
                play_sound_win(game->audio);
                // Adding a display window would require adding of text
                // so loading of fonts and connection of SDL2_ttf
                // which could be done but tbh not worth it today
                printf("You win!");
            }
            break;
        }
    }
    if (game_ball_check_block_collision(game, &game->paddle) && game->audio != NULL)
    {
        play_sound_hit(game->audio);
    }
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
        game_ball_die(game);
    }
}

void game_reset_ball_and_paddle(Game *game)
{
    Vector2 start_pos = vec2_add(vec2(DEFAULT_WINDOW_WIDTH / 2.f, DEFAULT_WINDOW_HEIGHT * 0.9f), vec2(10, 10));
    init_ball(&game->ball, vec2_add(start_pos, vec2(50, -15.f)), 5.f);
    init_block(&game->paddle, rect(start_pos, vec2(100, 10)), EPBC_LightGray, 0);
}

int is_game_finished(Game const *game)
{
    for (uint32_t i = 0; i < BLOCK_COUNT_TOTAL; i++)
    {
        if (valid_block(&game->blocks[i]))
        {
            return 0;
        }
    }
    return 1;
}

void game_ball_die(Game *game)
{
    if (game->audio != NULL)
    {
        play_sound_fail(game->audio);
    }
    game_reset_ball_and_paddle(game);
    game->ball_launched = 0;
}