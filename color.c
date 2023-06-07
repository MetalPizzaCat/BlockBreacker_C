#include "color.h"

SDL_Color get_block_color(EBlockColor color)
{
    SDL_Color res;
    res.a = 255;
    switch (color)
    {
    case EBC_Black:
        res.r = 0x00;
        res.g = 0x00;
        res.b = 0x00;
        break;
    case EBC_Blue:
        res.r = 0x00;
        res.g = 0x00;
        res.b = 0x80;
        break;
    case EBC_Green:
        res.r = 0x00;
        res.g = 0x80;
        res.b = 0x00;
        break;
    case EBC_Cyan:
        res.r = 0x00;
        res.b = 0x80;
        res.g = 0x80;
        break;
    case EBC_Red:
        res.r = 0x80;
        res.g = 0x00;
        res.b = 0x00;
        break;
    case EBC_Magenta:
        res.r = 0x80;
        res.g = 0x00;
        res.b = 0x80;
        break;
    case EBC_Brown:
        res.r = 0x80;
        res.b = 0x80;
        res.g = 0x00;
        break;
    case EBC_LightGray:
        res.r = 0xc0;
        res.b = 0xc0;
        res.g = 0xc0;
        break;
    case EBC_DarkGray:
        res.r = 0x80;
        res.b = 0x80;
        res.g = 0x80;
        break;
    case EBC_LightBlue:
        res.r = 0x00;
        res.b = 0xFF;
        res.g = 0x00;
        break;
    case EBC_LightGreen:
        res.r = 0x00;
        res.g = 0x00;
        res.b = 0xFF;
        break;
    case EBC_LightCyan:
        res.r = 0x00;
        res.g = 0xff;
        res.b = 0xff;
        break;
    case EBC_LightRed:
        res.r = 0xFF;
        res.g = 0x00;
        res.b = 0x00;
        break;
    case EBC_LightMagenta:
        res.r = 0xff;
        res.g = 0x00;
        res.b = 0xff;
        break;
    case EBC_Yellow:
        res.r = 0xff;
        res.g = 0xff;
        res.b = 0x00;
        break;
    case EBC_White:
        res.r = 0xff;
        res.g = 0xff;
        res.b = 0xff;
        break;
    default:
        break;
    }
    return res;
}