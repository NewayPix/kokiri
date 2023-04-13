#include <iostream>
#include <cstdint>

#include "core/game.hpp"
#include "core/functions.hpp"
#include "core/sound/track.hpp"
#include "graphics/sdl/sprite.hpp"

int main(int argc, char *argv[]) {
    using namespace Kokiri::Core;
    using namespace Kokiri::Graphics::SDL;

    Game game("A Game", 1024, 600);

    // create assets
    std::vector<Sprite> assets;

    Track bgm("stateStage.ogg");
    Track effect("boom.wav");

    Sprite background(game.get_window(), "ocean.jpg");

    assets.push_back(background);

    game.bind(FunctionType::Render, [&game, assets](){
        for (auto asset: assets) {
            asset.render(0, 0);
        }
    });

    effect.play(1);
    bgm.play(1);

    game.loop();
}

