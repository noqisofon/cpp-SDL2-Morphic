#include "morphic/Color.hxx"

namespace morphic {

    Color::Color()
        : r(0), g(0), b(0), a(0) {}
    Color::Color(uint8_t _r, uint8_t _g, uint8_t _b)
        : r(_r), g(_g), b(_b), a(255) {}
    Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
        : r(_r), g(_g), b(_b), a(_a) {}

    Color::Color(Color &other)
        : r(other.r), g(other.g), b(other.b), a(other.a) {
    }

    Color Color::red()   { return { 0x80, 0x00, 0x00 }; }

    Color Color::green() { return { 0x00, 0x80, 0x00 }; }

    Color Color::blue()  { return { 0x00, 0x00, 0x80 }; }

    std::ostream &operator<<(std::ostream &os, const Color &a_color) {
        os << "rgba(" << (uint32_t)a_color.r << ", " << (uint32_t)a_color.g
           << ", " << (uint32_t)a_color.b << ", " << (uint32_t)a_color.a
           << ")";

        return os;
    }
} // namespace morphic
