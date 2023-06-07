#pragma once
#include <stdlib.h>
#include <SDL2/SDL.h>

enum BlockColor
{
    Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Brown,
    LightGray,
    DarkGray,
    LightBlue,
    LightGreen,
    LightCyan,
    LightRed,
    LightMagenta,
    Yellow,
    White,
};

enum BlockState
{
    Normal,
    Damaged,
    Destroyed
};

struct Block
{
    float x;
    float y;
    BlockState state;
    BlockColor color;
};

typedef struct Block BG_Block;

BG_Block *create_block(float x, float y, BlockColor color)
{
    BG_Block *block = malloc(sizeof(BG_Block));
    block->x = x;
    block->y = y;
    block->state = BlockState::Normal;
    return block;
}

void draw_block(BG_Block* block, SDL_Surface* target_surface)
{

}

void free_block(BG_Block *block)
{
    free(block);
}