#include "./internal.hxx"

#include "morphic/RectangleMorph.hxx"

namespace morphic {

    RectangleMorph::RectangleMorph()
        : _Super() {}
    RectangleMorph::RectangleMorph(int32_t _x, int32_t _y, uint32_t _width, uint32_t _height)
        : _Super(_x, _y) {
        bounds.width  = _width;
        bounds.height = _height;
    }

    void RectangleMorph::display(SDL_Renderer *renderer) {
        SDL_Rect clip = {bounds.x, bounds.y,
            static_cast<int32_t>(bounds.width), static_cast<int32_t>(bounds.height)};

        // 前景を描画します。
        ::SDL_SetRenderDrawColor(renderer,
                                 foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
        ::SDL_RenderFillRect(renderer, &clip);

        // 縁を描画します。
        ::SDL_SetRenderDrawColor( renderer,
                                  edgeColor.r, edgeColor.g, edgeColor.b, edgeColor.a );
        ::SDL_RenderDrawRect( renderer, &clip );
    }

}
