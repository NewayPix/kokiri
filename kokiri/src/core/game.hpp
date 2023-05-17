#pragma once

#include <cstdint>
#include <functional>

#include "core/window.hpp"
#include "core/event.hpp"
#include "core/functions.hpp"
#include "core/references.hpp"
#include "core/sound/sound.hpp"

#include "graphics/opengl/renderer2d.hpp"
#include "graphics/sdl/renderer2d.hpp"

namespace Kokiri {
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
        ScopedRef<Sound> m_sound;
        SharedRef<Event> m_event;
        SharedRef<Window> m_window;
        ScopedRef<Graphics::OpenGL::Renderer2D> m_opengl_renderer;
        ScopedRef<Graphics::SDL::Renderer2D> m_sdl_renderer;

        // stored functions that a user would then provide through bind.
        std::map<FunctionType, Function<void>> m_functions;
    private:
        void render();
        void update();
        void event();
    public:
        Game(const std::string& title, int width, int height);
        ~Game();

        void init();

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

        SharedRef<Event> get_event();
    };
}