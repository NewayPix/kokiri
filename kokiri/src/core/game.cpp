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

            auto window_properties = Window::WindowProperties{
                .width = width,
                .height = height,
                .flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN,

                .title = title
            };

            m_window = make_shared<Window>(window_properties);
            m_renderer = make_scope<Graphics::OpenGL::Renderer2D>(m_window);

            m_event = make_scope<Event>();

            loop();
        }

        Game::~Game() {
            m_renderer.get()->~Renderer2D();
            m_window.get()->~Window();
            SDL_Quit();
        }


        void Game::init(std::function<void()> init) {
            init();
        }

        void Game::update(std::function<void(double)> update) {

        }

        void Game::event(std::function<void()> event) {

        }

        void Game::loop() {
            while (m_properties.is_running) {

                SDL_Delay(5);
            }
        }
    }
}