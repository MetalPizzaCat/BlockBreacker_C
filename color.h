#pragma once
#include <SDL2/SDL.h>

/// @brief Enum that describes all of the colors available to the system. Colors taken from ms-dos 16-bit palette
typedef enum
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
} EBlockColor;

/// @brief Enum that describes all colors that are available to use for object generation(limited to allow easier shading)
typedef enum
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
} EPrimaryBlockColor;

/// @brief All possible states of the block
typedef enum
{
    EBS_Normal,
    EBS_Damaged,
    EBS_Destroyed
} EBlockState;

// Simple way of calculating sharing offset :3
#define COLOR_PRIMARY_OFFSET EBC_White - EPBC_LightGray

/// @brief Gets rgba value for the color from the color list
/// @param color Color to convert
/// @return SDL_Color with RGBA values for the given color
SDL_Color get_block_color(EBlockColor color);