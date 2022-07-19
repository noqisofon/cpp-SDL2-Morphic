#include "morphic/Color.hxx"

namespace morphic {

    Color::Color() : red(0), green(0), blue(0), alpha(0) {}
    Color::Color(uint8_t r, uint8_t g, uint8_t b)
        : red(r), green(g), blue(b), alpha(255) {}
    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : red(r), green(g), blue(b), alpha(a) {}

    Color::Color(Color &other)
        : red(other.red), green(other.green), blue(other.blue), alpha(other.alpha) {
    }

    std::ostream &operator<<(std::ostream &os, const Color &a_color) {
        os << "rgba(" << (uint32_t)a_color.red << ", " << (uint32_t)a_color.green
           << ", " << (uint32_t)a_color.blue << ", " << (uint32_t)a_color.alpha
           << ")";

        return os;
    }
} // namespace morphic
