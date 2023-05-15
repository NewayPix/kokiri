#include <iostream>
#include <cstdint>

#include "core/game.hpp"
#include "core/functions.hpp"
#include "core/sound/track.hpp"
#include "graphics/sdl/sprite.hpp"

int main(int argc, char *argv[]) {
    using namespace Kokiri;
    using namespace Kokiri::Graphics::SDL;

    Game game("A Game", 1024, 600);

    Track bgm("stageState.ogg");
    Track effect("boom.wav");

    Sprite background(game.get_window(), "ocean.jpg");

    game.bind(FunctionType::Render, [&game, &background](){
        background.render(0, 0);
    });

    effect.play(1);
    bgm.play(1);

    game.loop();

    return 0;
}

