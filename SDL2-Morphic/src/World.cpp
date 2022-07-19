#include "./internal.hxx"

#include "morphic/World.hxx"

namespace morphic {
World::World()
    : quited_(false), should_window_close_(false), window_(nullptr),
      renderer_(nullptr), screen_bounds_(0, 0, 640, 480),
      background_color(35, 59, 108) {}

World::~World() {
    dispose();
}

int32_t World::run() {
    // 初期化
    if (!init()) {
        return EXIT_FAILURE;
    }

    // メインループ
    while (!should_window_close_) {
        // 画面の消去
        prepareSchene();
        // イベント処理
        eventProcess();
        // シーン描画
        presentScene();

        // あとはこの辺で FPS を刻む。
    }

    return EXIT_SUCCESS;
}

void World::addSubmorph(std::shared_ptr<Morph> &a_morph) {
    submorphs_.push_back(a_morph);
}

bool World::init() {
    if (::SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Couldn't initialize SDL: " << ::SDL_GetError()
                  << std::endl;
        return false;
    }

    uint32_t window_flags = SDL_WINDOW_SHOWN;

    window_ = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, screen_bounds_.width,
                               screen_bounds_.height, window_flags);
    if (!window_) {
        std::cerr << "Failed to open " << screen_bounds_.width << " x "
                  << screen_bounds_.height << " window: " << ::SDL_GetError()
                  << std::endl;

        return false;
    }

    int32_t renderer_index = -1;
    uint32_t renderer_flags =
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    renderer_ = SDL_CreateRenderer(window_, renderer_index, renderer_flags);
    if (!renderer_) {
        std::cerr << "Failed to create renderer: " << ::SDL_GetError()
                  << std::endl;

        return false;
    }
    return true;
}

void World::prepareSchene() {
    SDL_SetRenderDrawColor(renderer_, background_color.red,
                           background_color.green, background_color.blue,
                           background_color.alpha);
    SDL_RenderClear(renderer_);
}

void World::eventProcess() {
    SDL_Event an_event;

    while (SDL_PollEvent(&an_event)) {
        switch (an_event.type) {
        case SDL_QUIT:
            should_window_close_ = true;
            break;

        default:
            break;
        }
    }
}

void World::presentScene() {
    // TODO: submorph を表示する。
    for (auto &a_morph : submorphs_) {
        a_morph->display(renderer_);
    }

    SDL_RenderPresent(renderer_);
}

void World::dispose() {
    if (quited_) {
        return;
    }
    if (!renderer_) {
        SDL_DestroyRenderer(renderer_);
    }
    if (!window_) {
        SDL_DestroyWindow(window_);
    }
    ::SDL_Quit();
    quited_ = true;
}
} // namespace morphic
