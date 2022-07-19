#pragma once

#include <cstdint>
#include <iostream>

namespace morphic {
struct Point;

struct Rect {
    Rect();
    Rect(int32_t _x, int32_t _y, uint32_t _width, uint32_t _height);

    int32_t bottom() const;

    Point bottomCenter() const;
    Point bottomLeft() const;
    Point bottomRight() const;

    Point center() const;

    int32_t left() const;
    
    Point leftTop() const;

    Point leftCenter() const;

    int32_t right() const;

    int32_t top() const;

    friend std::ostream &operator<<(std::ostream &os, const Rect &a_rect);

    int32_t x;
    int32_t y;

    uint32_t width;
    uint32_t height;
};
} // namespace morphic