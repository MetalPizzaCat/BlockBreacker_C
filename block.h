#pragma once
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "geometry.h"
#include "color.h"

/// @brief Static block that can be destroyed by a ball
typedef struct
{
    /// @brief Rectangle that describes position and size of the block
    Rect collision_rect;
    /// @brief Current state of the block
    EBlockState state;
    /// @brief Color of the block
    EPrimaryBlockColor color;
} Block;

/// @brief Initialises value in block instance
/// @param block Instance of the block to update
/// @param rect Collision rect of the block
/// @param color Color of the block
void init_block(Block *block, Rect rect, EPrimaryBlockColor color);

/// @brief Renders the block to the renderer
/// @param block
/// @param render
void draw_block(Block const *block, SDL_Renderer *render);

/// @brief Damages the block
/// @param block
void damage_block(Block *block);

/// @brief Is block valid for the game(not destroyed)
/// @param block
/// @return 1 if block is not destroyed 0 otherwise
int valid_block(Block const *block);

/// @brief Frees any memory used by the block
/// @param block
void free_block(Block *block);