#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "./Color.hxx"
#include "./Morph.hxx"
#include "./Rect.hxx"

namespace morphic {
class Morph;

class World {
  public:
    World();
    ~World();

  public:
    int32_t run();
    void addSubmorph(std::shared_ptr<Morph> &a_morph);

  private:
    bool init();
    void prepareSchene();
    void eventProcess();
    void presentScene();
    void dispose();

  private:
    bool quited_;
    bool should_window_close_;

    SDL_Window *window_;
    SDL_Renderer *renderer_;

    Color background_color;
    Rect screen_bounds_;

    std::vector<std::shared_ptr<Morph>> submorphs_;
};
} // namespace morphic