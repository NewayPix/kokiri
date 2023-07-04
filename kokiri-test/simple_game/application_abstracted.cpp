#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>

#include <SDL2/SDL.h>

#include "core/game.hpp"
#include "core/event.hpp"
#include "core/scene.hpp"
#include "core/types.hpp"
#include "core/functions.hpp"
#include "core/sound/track.hpp"
#include "core/debug/log.hpp"

#include "graphics/sdl/sprite.hpp"

void test_1();
void test_2();
void test_3();

int main(int argc, char *argv[]) {
    test_3();

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
}


void test_3() {
    using namespace Kokiri;
    using namespace Kokiri::Math;
    using namespace Kokiri::Graphics::SDL;

    Game game("A Game", 1024, 600);

    game.load("main-bgm", "stageState.ogg");
    game.load("ocean-background", "ocean.jpg");

    game.loop();
    game.quit();
}

/*void test_4() {
    using namespace Kokiri;
    using namespace Kokiri::Math;
    using namespace Kokiri::Graphics::SDL;

    Game game("A Game", 1024, 600);

    //Track bgm("stageState.ogg");
    //Track effect("boom.wav");

    //Sprite background(game.get_window(), "ocean.jpg");

    game.load("ocean.jpg");
    game.load("stageState.ogg");
    game.load("boom.wav");

    Scene menu_scene("menu");
    Scene play_scene("play");
    Scene settings_scene("settings");
    Scene game_over_scene("over");

    game.set_active_scene("play")

    Entity alien("alien");
    Entity penguin("penguin");

    alien.add_component(game.get_component("ocean.jpg"));
    alien.add_component(game.get_component("shoot.ogg"));

    play_scene.add(alien);

    play_scene.bind(FunctionType::Render, [alien](){

    });

    play_scene.bind(FunctionType::Update, [alien](){

    });

    play_scene.bind(FunctionType::Event, [alien, penguin](){
        auto e = game.get_event();

        if (e.get()->is_keyboard_press(Event::Key::UP)) {
            penguin.
        }
    });

    std::vector<std::pair<v2<int>, Sprite*>> assets;
}*/