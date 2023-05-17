#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>

#include "core/game.hpp"
#include "core/event.hpp"
#include "core/types.hpp"
#include "core/functions.hpp"
#include "core/sound/track.hpp"
#include "core/debug/log.hpp"

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
    using namespace Kokiri::Math;
    using namespace Kokiri::Graphics::SDL;

    Game game("A Game", 1024, 600);

    Track bgm("stageState.ogg");
    Track effect("boom.wav");

    Sprite background(game.get_window(), "ocean.jpg");

    std::vector<std::pair<v2<int>, Sprite*>> assets;

    game.bind(FunctionType::Render, [&game, &background, &assets](){
        background.render(0, 0);

        for (const auto& asset : assets) {
            auto p = asset.first;
            auto s = asset.second;

            s->render(p.x, p.y);
        }
    });

    game.bind(FunctionType::Event, [&game, &assets]() {
        auto e = game.get_event();

        if (e.get()->is_mouse_click(Event::Mouse::LeftButton)) {
            auto p = e.get()->get_mouse_position();
            auto s = new Sprite(game.get_window(), "penguin.png");

            Log::info("click: ", p.x, p.y);

            assets.push_back(std::make_pair(p, s));
        }
    });

    game.loop();

    // clean everything
    for (const auto& asset : assets) {
        delete asset.second;
    }

    return 0;
}

