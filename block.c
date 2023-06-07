#include "block.h"

BG_Block *create_block(float x, float y, float width, float height, EPrimaryBlockColor color)
{
    BG_Block *block = malloc(sizeof(BG_Block));
    block->x = x;
    block->y = y;
    block->width = width;
    block->height = height;
    block->state = EBS_Normal;
    block->color = color;
    return block;
}

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
    }
    return res;
}

void draw_block(BG_Block *block, SDL_Renderer *render)
{
    SDL_Color prim_color = get_block_color((EBlockColor)block->color);
    SDL_SetRenderDrawColor(render, prim_color.r, prim_color.g, prim_color.b, prim_color.a);
    SDL_FRect primary_rect;
    primary_rect.x = block->x;
    primary_rect.y = block->y;
    primary_rect.w = block->width;
    primary_rect.h = block->height;
    SDL_RenderFillRectF(render, &primary_rect);

    SDL_Color sec_color = get_block_color(block->color + COLOR_PRIMARY_OFFSET);
    SDL_SetRenderDrawColor(render, sec_color.r, sec_color.g, sec_color.b, sec_color.a);
    SDL_FRect secondary_rect;
    secondary_rect.x = block->x + block->width * ((1.f - BLOCK_INNER_COLOR_SIZE_PERCENT) / 2.f);
    secondary_rect.y = block->y + block->height * ((1.f - BLOCK_INNER_COLOR_SIZE_PERCENT) / 2.f);
    secondary_rect.w = block->width * BLOCK_INNER_COLOR_SIZE_PERCENT;
    secondary_rect.h = block->height * BLOCK_INNER_COLOR_SIZE_PERCENT;
    SDL_RenderFillRectF(render, &secondary_rect);
}

void free_block(BG_Block *block)
{
    free(block);
}