#include "block.h"
#include "geometry.h"
void init_block(Block *block, Rect rect, EPrimaryBlockColor color)
{
    block->collision_rect = rect;
    block->state = EBS_Normal;
    block->color = color;
}

void draw_block(Block const *block, SDL_Renderer *render)
{
    SDL_Color prim_color = get_block_color((EBlockColor)block->color);
    SDL_SetRenderDrawColor(render, prim_color.r, prim_color.g, prim_color.b, prim_color.a);
    SDL_FRect primary_rect;
    primary_rect.x = block->collision_rect.position.x;
    primary_rect.y = block->collision_rect.position.y;
    primary_rect.w = block->collision_rect.size.x;
    primary_rect.h = block->collision_rect.size.y;
    SDL_RenderFillRectF(render, &primary_rect);

    SDL_Color sec_color = get_block_color(block->color + COLOR_PRIMARY_OFFSET);
    SDL_SetRenderDrawColor(render, sec_color.r, sec_color.g, sec_color.b, sec_color.a);
    SDL_FRect secondary_rect;
    secondary_rect.x = block->collision_rect.position.x + block->collision_rect.size.x * ((1.f - BLOCK_INNER_COLOR_SIZE_PERCENT) / 2.f);
    secondary_rect.y = block->collision_rect.position.y + block->collision_rect.size.y * ((1.f - BLOCK_INNER_COLOR_SIZE_PERCENT) / 2.f);
    secondary_rect.w = block->collision_rect.size.x * BLOCK_INNER_COLOR_SIZE_PERCENT;
    secondary_rect.h = block->collision_rect.size.y * BLOCK_INNER_COLOR_SIZE_PERCENT;
    SDL_RenderFillRectF(render, &secondary_rect);
}

void free_block(Block *block)
{
    free(block);
}