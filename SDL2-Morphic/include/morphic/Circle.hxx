#pragma once

#include <iostream>

#include "morphic/ShapeMorph.hxx"

namespace morphic {
class Circle : public ShapeMorph {
    using _Super = ShapeMorph;

  public:
    Circle();
    Circle(int32_t x__, int32_t y__, int32_t r__);

    friend std::ostream &operator<<(std::ostream &os, const Circle &a_color);

    void display(SDL_Renderer *renderer);

    int32_t radius;
};
} // namespace morphic