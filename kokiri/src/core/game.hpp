#pragma once

#include <cinttypes>
#include <functional>

#include "core/window.hpp"
#include "core/event.hpp"
#include "core/references.hpp"

namespace Kokiri {
    namespace Core {
        class Game {
        private:
            struct GameProperties {
                bool is_running;
                bool is_fullscreen;

                uint16_t fps;
                uint16_t target_fps;
            };

            // local game properties
            GameProperties m_properties;

            void loop();

            // Game resources
            Scope<Event> m_event;
            Scope<Window> m_window;
        public:
            Game();
            ~Game();

            void init(std::function<void> callback);
            void update(std::function<void(double dt)> callback);
            void event(std::function<void> callback);
        };
    }
}