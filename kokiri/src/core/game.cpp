#include "kkr.hpp"
#include "game.hpp"

#include <SDL2/SDL.h>

namespace Kokiri {
    namespace Core {

        Game::Game() {
            m_properties = GameProperties{
                .is_running = true,
                .is_fullscreen = false,

                .fps = 0,
                .target_fps = 60
            };

            //m_window = make_scope<Window>();
            //m_event = make_scope<Event>();

            loop();
        }

        Game::~Game() {}


        void Game::loop() {
            while (m_properties.is_running) {
                SDL_PollEvent(m_event.get()->get());
            }
        }

    }
}