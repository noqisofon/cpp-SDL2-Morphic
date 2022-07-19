#include "morphic/Vector2.hxx"

namespace morphic {
Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}

std::ostream &operator<<(std::ostream &os, const Vector2 &a_vector2) {
    os << "Vector2(" << a_vector2.x << ", " << a_vector2.y << ")";

    return os;
}
} // namespace morphic
