#pragma once

#include <cinttypes>
#include <functional>

#include "core/window.hpp"
#include "core/event.hpp"
#include "core/references.hpp"

#include "graphics/opengl/renderer2d.hpp"

namespace Kokiri {
    namespace Core {
        class Game {
        private:
            struct GameProperties {
                bool is_running;
                bool is_fullscreen;

                uint16_t fps;
                uint16_t target_fps;

                int width;
                int height;
            };

            // local game properties
            GameProperties m_properties;

            void loop();

            // game resources
            Scope<Event> m_event;
            Shared<Window> m_window;
            Scope<Graphics::OpenGL::Renderer2D> m_renderer;
        public:
            Game(const std::string& title, int width, int height);
            ~Game();

            void init(std::function<void()> init);
            void update(std::function<void(double dt)> update);
            void event(std::function<void()> event);
        };
    }
}