#pragma once

#include <cstdint>
#include <functional>

#include "core/window.hpp"
#include "core/event.hpp"
#include "core/functions.hpp"
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

            // stored functions that a user would then provide through bind.
            std::map<FunctionType, Function<void>> m_functions;
        public:
            Game(const std::string& title, int width, int height);
            ~Game();

            void init();
            void render();
            void update();
            void event();

            /**
             * @brief
             *
             * @param type
             * @param function
             */
            void bind(FunctionType type, Function<void> function);

            void loop();
            void quit();

            // this is to tie a knot when creating textures from the user side
            // of view (need to redesign this!)
            SharedRef<Window> get_window();
        };
    }
}