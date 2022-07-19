#include "morphic/Rect.hxx"
#include "morphic/Point.hxx"

namespace morphic {

    Rect::Rect() : x(0), y(0), width(0), height(0) {}
    Rect::Rect(int32_t _x, int32_t _y, uint32_t _width, uint32_t _height)
        : x(_x), y(_y), width(_width), height(_height) {}

    int32_t Rect::bottom() const { return static_cast<int32_t>(y + height); }

    Point Rect::bottomCenter() const { return {right() / 2, bottom()}; }
    Point Rect::bottomLeft() const { return {left(), bottom()}; }
    Point Rect::bottomRight() const { return {right(), bottom()}; }

    Point Rect::center() const { return {right() / 2, bottom() / 2}; }

    int32_t Rect::left() const { return x; }

    Point Rect::leftTop() const { return {x, y}; }

    Point Rect::leftCenter() const { return {left(), bottom() / 2}; }

    int32_t Rect::right() const { return static_cast<int32_t>(x + width); }

    int32_t Rect::top() const { return y; }

    std::ostream &operator<<(std::ostream &os, const Rect &a_rect) {
        os << "Rect(" << a_rect.x << ", " << a_rect.y << ", " << a_rect.width
           << ", " << a_rect.height << ")";

        return os;
    }
} // namespace morphic
