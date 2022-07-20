#include <morphic/morphic.hxx>

int main(int argc, char **argv) {
    morphic::World the_world;

    auto a_circle = std::make_shared<morphic::Circle>(130, 130, 30);

    a_circle->edgeColor       = morphic::Color::white();
    a_circle->foregroundColor = morphic::Color::yellow();

    std::shared_ptr<morphic::Morph> a_morph(a_circle);

    the_world.addSubmorph(a_morph);

    return the_world.run();
}
