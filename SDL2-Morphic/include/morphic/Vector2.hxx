#pragma once

#include <iostream>

namespace morphic {
struct Vector2 {
    Vector2();
    Vector2(float _x, float _y);

    friend std::ostream &operator<<(std::ostream &os, const Vector2 &a_vector2);

    float x;
    float y;
};
} // namespace morphic