#include "./internal.hxx"

#include "morphic/Circle.hxx"

namespace morphic {
Circle::Circle() : _Super() , radius(0){}

Circle::Circle(int32_t x__, int32_t y__, int32_t r__)
    : _Super(x__, y__), radius(r__) {
    bounds.width = r__ * 2;
    bounds.height = r__ * 2;
}

void Circle::display(SDL_Renderer *renderer) {
    // 丸を描画したいところだが、SDL2 では四角しか描画できないようなので、とりあえず四角を描画することにする。
    SDL_Rect clip = {bounds.x, bounds.y, static_cast<int32_t>(bounds.width),
                     static_cast<int32_t>(bounds.height)};

    // 前景を描画します。
    ::SDL_SetRenderDrawColor(renderer,
                             foregroundColor.red, foregroundColor.green, foregroundColor.blue, foregroundColor.alpha);
    SDL_RenderFillRect(renderer, &clip);

    // 縁を描画します。
    ::SDL_SetRenderDrawColor( renderer,
                              edgeColor.red, edgeColor.green, edgeColor.blue, edgeColor.alpha );
    ::SDL_RenderDrawRect( renderer, &clip );
}

std::ostream &operator<<(std::ostream &os, const Circle &a_circle) {
    os << "Circle(" << a_circle.bounds.topLeft() << ", " << a_circle.radius
       << ")";

    return os;
}
} // namespace morphic
