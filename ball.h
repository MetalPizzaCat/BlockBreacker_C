#pragma once
#include <stdlib.h>
#include <SDL2/SDL.h>

struct Ball
{
    float x;
    float y;
    float size;
};

typedef struct Ball BG_Ball;

BG_Ball create_ball(float x, float y, float size);
void free_ball(BG_Ball * ball);