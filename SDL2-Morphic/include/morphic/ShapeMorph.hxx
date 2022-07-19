#pragma once

#include "Morph.hxx"

namespace morphic {
class ShapeMorph : public Morph {
    using _Super = Morph;
  public:
    ShapeMorph();
    ShapeMorph(int32_t x__, int32_t y__);

  public:
    Color edgeColor;
};
} // namespace morphic