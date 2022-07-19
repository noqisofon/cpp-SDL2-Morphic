#pragma once

#include "morphic/ShapeMorph.hxx"

namespace morphic {
    class RectangleMorph : public ShapeMorph {
        using _Super = ShapeMorph;

    public:
        RectangleMorph();
        RectangleMorph(int32_t _x, int32_t _y, uint32_t _width, uint32_t _height);

    public:
        void display(SDL_Renderer *renderer);
    };
}
