#pragma once
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "geometry.h"

/// @brief The movable ball that bounces around and kills everything
typedef struct
{
    /// @brief Collision rect of the ball
    Rect collision_rect;
    Vector2 velocity;
} Ball;

/// @brief Initialises instance of the ball
/// @param ball Instance to initialise
/// @param position Ball position(starting from the middle)
/// @param size radius of the ball
void init_ball(Ball *ball, Vector2 position, float size);
void draw_ball(Ball *ball, SDL_Renderer *render);
void free_ball(Ball *ball);