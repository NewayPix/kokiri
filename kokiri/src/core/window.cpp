#include "kkr.hpp"
#include "window.hpp"

namespace Kokiri {
    namespace Core {
        Window::Window(int width, int height, const std::string &title, int32_t flags) {

            if(SDL_Init(SDL_INIT_VIDEO) != 0) {
                Core::Log::error("failed to initialize SDL2 video system, reason ", SDL_GetError());
                exit(1);
            }

            auto window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

            if (window == nullptr) {
                Core::Log::error("failed to initialize window, reason ", SDL_GetError());
                exit(1);
            }

            auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if (renderer == nullptr) {
                Core::Log::error("failed to initialize renderer, reason ", SDL_GetError());
                exit(1);
            }

            m_window = window;
            m_window_renderer = renderer;

            m_width = width;
            m_height = height;
        }

        Window::~Window() {
            Core::Log::info("destroying renderer");
            SDL_DestroyRenderer(m_window_renderer);
            Core::Log::info("destroying window");
            SDL_DestroyWindow(m_window);
        }

        SDL_Window* Window::get_window() {
            return m_window;
        }

        SDL_Renderer* Window::get_renderer() {
            return m_window_renderer;
        }

        int Window::width() {
            return m_width;
        }

        int Window::height() {
            return m_height;
        }
    }
}