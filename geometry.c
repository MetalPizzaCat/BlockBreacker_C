#include "geometry.h"
#include <math.h>

Vector2 vec2(float x, float y)
{
    Vector2 vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

Vector2 vec2_add(Vector2 a, Vector2 b)
{
    Vector2 res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

Vector2 vec2_mul_f(Vector2 a, float m)
{
    Vector2 res;
    res.x = a.x * m;
    res.y = a.y * m;
    return res;
}

Rect rect(Vector2 pos, Vector2 size)
{
    Rect rect;
    rect.position = pos;
    rect.size = size;
    return rect;
}

int rect_does_intersect(Rect const *a, Rect const *b)
{
    // i took this code from older project written in rust where boxes have coords in the middle
    // and i have no idea how this works :3
    if ((b->size.x / 2.f + a->size.x / 2.f - (float)fabs(b->position.x + b->size.x / 4.f - a->position.x + a->size.x / 4.f)) <= 0.f)
    {
        return 0;
    }
    if ((b->size.y / 2.f + a->size.y / 2.f - (float)fabs(b->position.y + b->size.y / 4.f - a->position.y + a->size.y / 4.f)) <= 0.f)
    {
        return 0;
    }
    return 1;
}