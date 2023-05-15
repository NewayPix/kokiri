#include <iostream>
#include <cstdint>

#include "core/game.hpp"
#include "core/functions.hpp"
#include "core/sound/track.hpp"
#include "graphics/sdl/sprite.hpp"

void test_1();
void test_2();

int main(int argc, char *argv[]) {
    test_2();

    return 0;
}

void test_1() {
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
}

void test_2() {
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
}

