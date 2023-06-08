#include "keyhandler.h"

void init_key_handler(KeyHandler *handler, int allow_2d_motion)
{
    handler->allow_2d_motion = allow_2d_motion;
    handler->down_key_state = 0;
    handler->up_key_state = 0;
    handler->left_key_state = 0;
    handler->right_key_state = 0;
}

void handle_keyboard_event(KeyHandler *handler, SDL_Event *event)
{
    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.scancode)
        {
        case SDL_SCANCODE_RIGHT:
            handler->right_key_state = 1;
            break;
        case SDL_SCANCODE_LEFT:
            handler->left_key_state = 1;
            break;
        case SDL_SCANCODE_UP:
            handler->up_key_state = handler->allow_2d_motion;
            break;
        case SDL_SCANCODE_DOWN:
            handler->down_key_state = handler->allow_2d_motion;
            break;
        default:
            break;
        }
    }
    else if (event->type == SDL_KEYUP)
    {
        switch (event->key.keysym.scancode)
        {
        case SDL_SCANCODE_RIGHT:
            handler->right_key_state = 0;
            break;
        case SDL_SCANCODE_LEFT:
            handler->left_key_state = 0;
            break;
        case SDL_SCANCODE_UP:
            handler->up_key_state = 0;
            break;
        case SDL_SCANCODE_DOWN:
            handler->down_key_state = 0;
            break;
        default:
            break;
        }
    }
}