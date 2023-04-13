#pragma once

#include <cstdint>
#include <functional>

#include "core/window.hpp"
#include "core/event.hpp"
#include "core/references.hpp"
#include "core/sound/sound.hpp"

#include "graphics/opengl/renderer2d.hpp"
#include "graphics/sdl/renderer.hpp"

namespace Kokiri {
    namespace Core {
        class Game {
        private:
            struct GameProperties {
                bool is_running;
                bool is_fullscreen;
                bool is_debug;

                uint16_t fps;
                uint16_t target_fps;

                float target_frame_time; // the frame time objective

                int width;
                int height;
            };

            // local game properties
            GameProperties m_properties;

            // game resources
            ScopedRef<Event> m_event;
            ScopedRef<Sound> m_sound;
            SharedRef<Window> m_window;
            ScopedRef<Graphics::OpenGL::Renderer2D> m_renderer;
            ScopedRef<Graphics::SDL::Renderer> m_sdl_renderer;
        public:
            Game(const std::string& title, int width, int height);
            ~Game();

            void init(std::function<void()> init);
            void update(std::function<void(double dt)> update);
            void event(std::function<void()> event);

            void loop();
            void quit();
        };
    }
}