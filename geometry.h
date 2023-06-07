#pragma once

/// @brief A 2D vector with floating point values
typedef struct
{
    float x;
    float y;
} Vector2;

/// @brief Struct that describes a rectangle where location is top-left corner
typedef struct
{
    Vector2 position;
    Vector2 size;
} Rect;

/// @brief Creates a new Vector2 object
/// @param x X of the vector
/// @param y Y of the vector
/// @return new Vector2 object with values assigned
Vector2 vec2(float x, float y);

/// @brief Adds values of two vectors together
/// @param a
/// @param b
/// @return New vector with values that are equal to the sum
Vector2 vec2_add(Vector2 a, Vector2 b);

/// @brief Multiplies vector by a float value
/// @param a vector
/// @param m value
/// @return Multiplied vector
Vector2 vec2_mul_f(Vector2 a, float m);

/// @brief Creates a new instance of Rect
/// @param pos Position of the rectangle
/// @param size Size of the rectangle
/// @return created rectangle with values assigned
Rect rect(Vector2 pos, Vector2 size);