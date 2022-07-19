#include <morphic/morphic.hxx>

int main(int argc, char **argv) {
    morphic::World the_world;

    auto a_circle = std::make_shared<morphic::Circle>(30, 30, 30);

    a_circle->edgeColor       = morphic::Color {0x00, 0x00, 0x00};
    a_circle->foregroundColor = morphic::Color {0xff, 0xff, 0xff};

    std::shared_ptr<morphic::Morph> a_morph(a_circle);

    the_world.addSubmorph(a_morph);

    return the_world.run();
}
