#include "./internal.hxx"

#include "morphic/Morph.hxx"

namespace morphic {

    Morph::Morph() : bounds(0, 0, 0, 0) {}
    Morph::Morph(int32_t x__, int32_t y__) : bounds(x__, y__, 0, 0) {}

    void Morph::location(int32_t x, int32_t y) {
        bounds.x = x;
        bounds.y = y;
    }
} // namespace morphic
