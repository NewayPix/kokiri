#include "kkr.hpp"
#include "application.hpp"

namespace Kokiri {
    Application::Application(ApplicationWindow& window) {
        switch (window.type) {
            case ApplicationRenderType::OpenGL:
            {
                m_window = make_scope_ref<Window>(Window::WindowProperties{
                    .width = window.dimension.x,
                    .height = window.dimension.y,
                    .flags = SDL_WINDOW_OPENGL,

                    .title = window.title
                });

                m_opengl_renderer = make_scope_ref<Graphics::OpenGL::Renderer2D>(m_window);
            }
            break;
            case ApplicationRenderType::SDL:
            {
                m_window = make_scope_ref<Window>(Window::WindowProperties{
                    .width = window.dimension.x,
                    .height = window.dimension.y,
                    .flags = 0,

                    .title = window.title
                });

                m_sdl_renderer = make_scope_ref<Graphics::SDL::Renderer2D>(m_window);
            }
            break;
        }
    }

    Application::~Application() {}
}