#include "./internal.hxx"

#include "morphic/Color.hxx"

namespace morphic {

    Color::Color()
        : _Self( 0, 0, 0, 0 ) {}
    Color::Color(uint8_t _r, uint8_t _g, uint8_t _b)
        : _Self( _r, _g, _b, SDL_ALPHA_OPAQUE ) {}
    Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
        : r(_r), g(_g), b(_b), a(_a) {}

    Color::Color(Color &other)
        : _Self(other.r, other.g, other.b, other.a) {
    }

    Color Color::red()    { return { 234,  85,  80 }; }

    Color Color::green()  { return {   0, 169,  96 }; }

    Color Color::blue()   { return {   0, 117, 194 }; }

    Color Color::yellow() { return { 255, 220,   0 }; }

    Color Color::black()  { return {   0,   0,   0 }; }

    Color Color::white()  { return { 255, 255, 255 }; }

    std::ostream &operator<<(std::ostream &os, const Color &a_color) {
        os << "rgba("
           << (uint32_t)a_color.r << ", "
           << (uint32_t)a_color.g << ", "
           << (uint32_t)a_color.b << ", "
           << (uint32_t)a_color.a
           << ")";

        return os;
    }

} // namespace morphic
