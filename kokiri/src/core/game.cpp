#include "kkr.hpp"
#include "game.hpp"

#include <SDL2/SDL.h>

namespace Kokiri {
    namespace Core {
        Game::Game(const std::string& title, int width, int height) {
            m_properties = GameProperties{
                .is_running = true,
                .is_fullscreen = false,

                .fps = 0,
                .target_fps = 60,

                .width = width,
                .height = height,
            };

            m_window = make_scope<Window>(width, height, title, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
            m_renderer = make_scope<Graphics::OpenGL::Renderer2D>(m_window.get()->get_window());

            m_event = make_scope<Event>();

            loop();
        }

        Game::~Game() {
            m_renderer.get()->~Renderer2D();
            m_window.get()->~Window();
            SDL_Quit();
        }


        void Game::loop() {
            while (m_properties.is_running) {
            }
        }

        void Game::event(std::function<void> f) {
            SDL_PollEvent(m_event.get()->get());
        }

    }
}