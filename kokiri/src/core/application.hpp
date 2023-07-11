#pragma once

#include "core/game.hpp"
#include "core/window.hpp"
#include "core/references.hpp"
#include "core/types.hpp"

#include "graphics/opengl/renderer2d.hpp"
#include "graphics/sdl/renderer2d.hpp"

namespace Kokiri {
    class Application {
    private:
        SharedRef<Window> m_window;

        SharedRef<Graphics::OpenGL::Renderer2D> m_opengl_renderer;
        SharedRef<Graphics::SDL::Renderer2D> m_sdl_renderer;

        ScopedRef<Game> m_game;
    public:
        enum class ApplicationRenderType {
            SDL,
            OpenGL,
        };

        struct ApplicationWindow {
            std::string title;

            v2<u32> dimension;
            v2<u32> position;

            ApplicationRenderType type;
        };

        Application(ApplicationWindow& window);
        ~Application();
    };
}