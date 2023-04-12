#include <iostream>
#include <cstdint>

#include "core/game.hpp"

int main(int argc, char *argv[]) {
    using namespace Kokiri::Core;
    using namespace Kokiri::Graphics;
    using namespace Kokiri::Graphics::OpenGL;

    Game game("A Game", 800, 600);

    game.loop();
}