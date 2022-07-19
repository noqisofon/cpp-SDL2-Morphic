#pragma once

#include "./Color.hxx"
#include "./Point.hxx"
#include "./Rect.hxx"

namespace morphic {
class Morph {
  public:
    Morph();
    Morph(int32_t x__, int32_t y__);

  public:
    virtual void display(SDL_Renderer *renderer) = 0;

    Point location() const { return { bounds.x, bounds.y }; }
    void  location(int32_t x, int32_t y);

  public:
    Color foregroundColor;
    Rect bounds;
    //Vector2 velocity;
};
} // namespace morphic
