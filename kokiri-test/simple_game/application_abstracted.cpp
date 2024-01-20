#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>
#include <memory>

#include <SDL2/SDL.h>

#include "core/game.hpp"
#include "core/event.hpp"
#include "core/scene.hpp"
#include "core/types.hpp"
#include "core/functions.hpp"
#include "core/sound/track.hpp"
#include "core/debug/log.hpp"

#include "graphics/sdl/sprite.hpp"

void test_resources();
void test_scenes();

int main(int argc, char *argv[]) {
    test_scenes();

    return 0;
}

void test_resources() {
    using namespace Kokiri;
    using namespace Kokiri::Math;
    using namespace Kokiri::Graphics::SDL;

    Game game("A Game", 1024, 600);

    game.load(Game::Resource("bgm", "stageState.ogg", ComponentType::Soundtrack));
    game.load(Game::Resource("ocean", "ocean.jpg", ComponentType::Sprite));

    auto c = dynamic_cast<Sprite*>(game.retrieve("ocean"));

    Log::info("x -> ", c->get_width(), " y -> ", c->get_height());

    game.loop();
}

void test_scenes() {
    using namespace Kokiri;
    using namespace Kokiri::Math;
    using namespace Kokiri::Graphics::SDL;

    Game game("A Game", 1024, 600);

    auto level = new Scene(game.get_window(), "level");
    auto menu = new Scene(game.get_window(), "menu");
    auto over = new Scene(game.get_window(), "over");

    game.add_scene(menu);
    game.add_scene(level);
    game.add_scene(over);

    game.set_active_scene("level");

    game.load(Game::Resource("bgm", "stageState.ogg", ComponentType::Soundtrack));
    game.load(Game::Resource("shot", "boom.wav", ComponentType::Soundtrack));
    game.load(Game::Resource("background", "ocean.jpg", ComponentType::Sprite));
    game.load(Game::Resource("penguin", "penguin.png", ComponentType::Sprite));

    Entity::EntityProperties world_properties("background");
    world_properties.size.x = 1024;
    world_properties.size.y = 600;

    Entity world(world_properties);

    auto b = game.retrieve("background");
    auto m = game.retrieve("bgm");

    if (b == nullptr || m == nullptr) {
        Log::error("resource is null");
        return;
    }

    world.add_component(b);
    world.add_component(m);

    world.play("");

    auto p = dynamic_cast<Sprite*>(game.retrieve("penguin"));

    Entity::EntityProperties player_properties("player");
    player_properties.size.x = p->get_width();
    player_properties.size.y = p->get_height();

    Entity player(player_properties);

    player.add_component(game.retrieve("penguin"));

    // rendering order is VERY important
    level->add_entity(&player);
    level->add_entity(&world);

    level->bind(FunctionType::Render, [&game](){});

    level->bind(FunctionType::Event, [&game, &player]() {
        auto e = game.get_event();

        if (e.get()->is_mouse_click(Event::Mouse::LeftButton)) {
            auto p = e.get()->get_mouse_position();

            player.set_position(p);
        }
    });

    game.loop();
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