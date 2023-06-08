#pragma once
#include "window.h"
#include "ball.h"
#include "block.h"

/// @brief Struct that holds all of the information about the game
typedef struct
{
    /// @brief Game window
    GameWindow *window;
    /// @brief  All of the blocks present in the game
    Block blocks[BLOCK_COUNT_TOTAL];
    /// @brief Main ball that flies around
    Ball ball;
} Game;

/// @brief Init instance of a game
/// @param game Game to init
/// @param window valid window handle
void init_game(Game *game, GameWindow *window, uint64_t map);

/// @brief Updates all objects in the game
/// @param game Instance of the game
/// @param delta time since last frame
void update_game(Game *game, float delta);