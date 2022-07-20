#include "./internal.hxx"

#include "morphic/Renderer.hxx"
#include "morphic/Window.hxx"

namespace morphic {

    Renderer::Renderer(SDL_Renderer *renderer) : source_(renderer) {
    }

    Renderer::~Renderer() {
        if ( source_ ) {
            ::SDL_DestroyRenderer( source_ );
        }
    }

    int32_t Renderer::setDrawColor(const Color& a_color) {
        assert( source_ != nullptr );

        int32_t answer =  ::SDL_SetRenderDrawColor( source_,
                                                    a_color.r, a_color.g, a_color.b, a_color.a );

        assert( answer == 0 );

        return answer;
    }

    Color Renderer::getDrawColor() {
        uint8_t r, g, b, a;

        assert( source_ != nullptr );

        int32_t answer = ::SDL_GetRenderDrawColor( source_,
                                                   &r, &g, &b, &a );

        assert( answer == 0 );

        return { r, g, b, a };
    }

    int32_t Renderer::drawLine(const Point& start, const Point& last) {
        assert( source_ != nullptr );

        int32_t answer =  ::SDL_RenderDrawLine( source_,
                                                  start.x, start.y,
                                                  last.y , last.y );

        assert( answer == 0 );

        return answer;
    }

    int32_t Renderer::clear() {
        assert( source_ != nullptr );

        int32_t answer = ::SDL_RenderClear( source_ );

        assert( answer == 0 );

        return answer;
    }

    std::shared_ptr<Renderer> Renderer::create(Window &window, int32_t index, uint32_t flags) {
        SDL_Window   *window_source = window.getSource();

        assert( window_source != nullptr );
        
        SDL_Renderer *renderer      = ::SDL_CreateRenderer( window_source, index, flags );

        assert( renderer != nullptr );

        return std::shared_ptr<Renderer>( new Renderer( renderer ) );
    }
}
