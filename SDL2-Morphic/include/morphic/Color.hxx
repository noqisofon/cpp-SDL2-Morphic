#pragma once

#include <iostream>

namespace morphic {
struct Color {
    Color();
    Color(uint8_t r, uint8_t g, uint8_t b);
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    Color(Color &other);

    constexpr Color &operator=(const Color &other) {
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;

        return *this;
    }

    static Color red();
    static Color green();
    static Color blue();
    static Color yellow();

    friend std::ostream &operator<<(std::ostream &os, const Color &a_color);

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};
} // namespace morphic
