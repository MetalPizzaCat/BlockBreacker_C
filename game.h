#pragma once
#include "window.h"
#include "ball.h"
#include "block.h"
#include "audio.h"

/// @brief Struct that holds all of the information about the game
typedef struct
{
    /// @brief Game window
    GameWindow *window;
    /// @brief Audio manager used to play sounds in the game
    AudioManager *audio;
    /// @brief  All of the blocks present in the game
    Block blocks[BLOCK_COUNT_TOTAL];
    /// @brief Main ball that flies around
    Ball ball;
    /// @brief Paddle controllable by player
    Block paddle;
    int ball_launched;
} Game;

/// @brief Init instance of a game
/// @param game Game to init
/// @param window valid window handle
void init_game(Game *game, GameWindow *window, AudioManager *audio, uint64_t map);

/// @brief Updates all objects in the game
/// @param game Instance of the game
/// @param delta time since last frame
void update_game(Game *game, float delta);

/// @brief Perform ball collision check and reaction
/// @param game Game which stores the ball
/// @param block Block to check against
/// @return 1 if there was collision and 0 if there was not
int game_ball_check_block_collision(Game *game, Block *block);

/// @brief Make game perform logic necessary to consider ball dead
/// @param game Game itself
void game_ball_die(Game *game);

/// @brief Resets ball and paddle to the default position and awaits player input
/// @param game Game itself
void game_reset_ball_and_paddle(Game *game);