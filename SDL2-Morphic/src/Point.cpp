#include "morphic/Point.hxx"
#include "morphic/Rect.hxx"

namespace morphic {

    Point::Point() : x(0), y(0) {}
    Point::Point(int32_t _x, int32_t _y) : x(_x), y(_y) {}

    Rect Point::corner(int32_t x, int32_t y) const { return corner(Point(x, y)); }
    Rect Point::corner(const Point &other) const {
        return {x, y, static_cast<uint32_t>(other.x - x),
            static_cast<uint32_t>(other.y - y)};
    }

    std::ostream &operator<<(std::ostream &os, const Point &a_point) {
        os << "Point(" << a_point.x << ", " << a_point.y << ")";

        return os;
    }
} // namespace morphic
