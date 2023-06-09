#include "ball.h"
#include "block.h"

void draw_ball(Ball const *ball, SDL_Renderer *render)
{
    SDL_Color prim_color = get_block_color(EBC_Green);
    SDL_SetRenderDrawColor(render, prim_color.r, prim_color.g, prim_color.b, prim_color.a);
    SDL_FRect primary_rect;
    primary_rect.x = ball->collision_rect.position.x;
    primary_rect.y = ball->collision_rect.position.y;
    primary_rect.w = ball->collision_rect.size.x;
    primary_rect.h = ball->collision_rect.size.y;
    SDL_RenderFillRectF(render, &primary_rect);

    SDL_Color sec_color = get_block_color(EBC_LightMagenta);
    SDL_SetRenderDrawColor(render, sec_color.r, sec_color.g, sec_color.b, sec_color.a);
    SDL_FRect secondary_rect;
    secondary_rect.x = ball->collision_rect.position.x + ball->collision_rect.size.x / 4.f;
    secondary_rect.y = ball->collision_rect.position.y + ball->collision_rect.size.y / 4.f;
    secondary_rect.w = ball->collision_rect.size.x / 2.f;
    secondary_rect.h = ball->collision_rect.size.y / 2.f;
    SDL_RenderFillRectF(render, &secondary_rect);
}

void init_ball(Ball *ball, Vector2 position, float size)
{
    ball->collision_rect = rect(vec2_add(position, vec2(-size, -size)), vec2(size * 2.f, size * 2.f));
    ball->velocity = vec2((float)(rand() % 10) * 0.05f, (float)(rand() % 10) * -0.05f);
    ball->default_velocity = ball->velocity;
}
void free_ball(Ball *ball)
{
    free(ball);
}