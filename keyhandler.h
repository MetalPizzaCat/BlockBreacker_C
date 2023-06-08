#pragma once
#include <SDL2/SDL.h>
#include "game.h"

/// @brief Struct for handling player input
typedef struct
{
    /// @brief If true(1) up and down keys are handled as well if not up and down keys are ignored
    int allow_2d_motion;

    /// @brief Current state of the UP arrow key with 1 being held and 0 being not
    int up_key_state;

    /// @brief Current state of the DOWN arrow key with 1 being held and 0 being not
    int down_key_state;

    /// @brief Current state of the LEFT arrow key with 1 being held and 0 being not
    int left_key_state;

    /// @brief Current state of the RIGHT arrow key with 1 being held and 0 being not
    int right_key_state;

    /// @brief Current state of the RIGHT arrow key with 1 being held and 0 being not. Space key is meant to launch the ball after game starts
    int space_key_state;
} KeyHandler;

/// @brief Initialises value in the key handler object
/// @param allow_2d_motion
void init_key_handler(KeyHandler *handler, int allow_2d_motion);

/// @brief Updates states of the handled keys
/// @param handler Handler object
/// @param event Event to process
void handle_keyboard_event(KeyHandler *handler, SDL_Event const *event);