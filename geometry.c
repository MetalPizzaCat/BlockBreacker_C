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
    /*NOTE: i took this code from older project written in rust where boxes have coords in the middle
     This works by checking if distance between centers of the boxes is larger then sizes of the boxes
     and if it is then sides are far too far away from each other to be considered colliding
     we do this for both axis
     Note 2 electric boogalo: diving by 2 and 4 is simply there to adjust difference in how boxes are handled
     This project:
    this project
        #--w--*
        |     |
        h     h
        |     |
        *--w--*
     original project
        *-------*
        |  |h   |
        |-w-#-w-|
        |  |h   |
        *-------*

        where # is the root point(point from where position is calculated)
        because of this W(original) = W(current) / 2 with same for the height
    */
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