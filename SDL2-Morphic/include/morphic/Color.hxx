#pragma once

#include <iostream>

namespace morphic {
struct Color {
    Color();
    Color(uint8_t r, uint8_t g, uint8_t b);
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    Color(Color &other);

    constexpr Color &operator=(const Color &other) {
        red = other.red;
        green = other.green;
        blue = other.blue;
        alpha = other.alpha;

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Color &a_color);

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};
} // namespace morphic