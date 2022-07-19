#pragma once

#include <iostream>

namespace morphic {
struct Rect;

struct Point {
    Point();
    Point(int32_t x, int32_t y);

    Rect corner(int32_t x, int32_t y) const;
    Rect corner(const Point &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Point &a_point);

    int32_t x;
    int32_t y;
};
} // namespace morphic