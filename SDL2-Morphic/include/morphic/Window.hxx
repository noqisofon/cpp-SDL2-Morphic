#pragma once

namespace morphic {

    class Window {
        using _Super =  Window;

    protected:
        Window(SDL_Window *window);

    public:
        ~Window();

    public:
        SDL_Window *getSource() const { return source_; }

    private:
        SDL_Window *source_;
    };
}
