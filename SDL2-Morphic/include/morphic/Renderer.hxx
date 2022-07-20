#pragma once

#include "morphic/Color.hxx"
#include "morphic/Point.hxx"

namespace morphic {

    class Window;
    
    class Renderer {
        using _Super =  Renderer;

    protected:
        Renderer(SDL_Renderer *renderer);

    public:
        ~Renderer();

    public:
        SDL_Renderer *getSource() const { return source_; }

        int32_t setDrawColor(const Color& a_color);
        Color   getDrawColor();

        int32_t drawLine(const Point& start, const Point& last);

        int32_t clear();

        static std::shared_ptr<Renderer> create(Window &window,
                                                int32_t index = -1,
                                                uint32_t flags = SDL_RENDERER_ACCELERATED);
        
    private:
        SDL_Renderer *source_;
    };
}
