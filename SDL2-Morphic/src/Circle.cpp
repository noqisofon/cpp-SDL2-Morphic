#include "./internal.hxx"

#include "morphic/Circle.hxx"

namespace morphic {
Circle::Circle() : _Super() , radius(0) {}

Circle::Circle(int32_t x__, int32_t y__, int32_t r__)
    : _Super(x__, y__), radius(r__) {
    bounds.width = r__ * 2;
    bounds.height = r__ * 2;
}

void Circle::display(SDL_Renderer *renderer) {
    // 前景を描画します。
    filledCircleRGBA( renderer,
                      bounds.x, bounds.y,
                      radius,
                      foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a );

    // 縁を描画します。
    circleRGBA( renderer,
                bounds.x, bounds.y,
                radius,
                edgeColor.r, edgeColor.g, edgeColor.b, edgeColor.a );
}

std::ostream &operator<<(std::ostream &os, const Circle &a_circle) {
    os << "Circle(" << a_circle.bounds.topLeft() << ", " << a_circle.radius
       << ")";

    return os;
}
} // namespace morphic
