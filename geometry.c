#include "geometry.h"

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