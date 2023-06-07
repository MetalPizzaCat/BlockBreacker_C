#pragma once
#include <stdlib.h>
#include <SDL2/SDL.h>

enum BlockColor
{
    EBC_Black,
    EBC_Blue,
    EBC_Green,
    EBC_Cyan,
    EBC_Red,
    EBC_Magenta,
    EBC_Brown,
    EBC_LightGray,
    EBC_DarkGray,
    EBC_LightBlue,
    EBC_LightGreen,
    EBC_LightCyan,
    EBC_LightRed,
    EBC_LightMagenta,
    EBC_Yellow,
    EBC_White,
    // Total color count
    EBC_MAX
};

enum PrimaryBlockColor
{
    EPBC_Black,
    EPBC_Blue,
    EPBC_Green,
    EPBC_Cyan,
    EPBC_Red,
    EPBC_Magenta,
    EPBC_Brown,
    EPBC_LightGray,
    // Total primary color count
    EPBNC_MAX
};

enum BlockState
{
    EBS_Normal,
    EBS_Damaged,
    EBS_Destroyed
};

typedef enum BlockColor EBlockColor;
typedef enum BlockState EBlockState;
typedef enum PrimaryBlockColor EPrimaryBlockColor;

#define COLOR_PRIMARY_OFFSET EBC_White - EPBC_LightGray

struct Block
{
    float x;
    float y;
    float width;
    float height;
    EBlockState state;
    EPrimaryBlockColor color;
};

typedef struct Block BG_Block;

BG_Block *create_block(float x, float y, float width, float height, EPrimaryBlockColor color);

SDL_Color get_block_color(EBlockColor color);

void draw_block(BG_Block *block, SDL_Renderer *render);

void free_block(BG_Block *block);