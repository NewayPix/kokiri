#include "kkr.hpp"
#include "game.hpp"
#include "timer.hpp"

#include <SDL2/SDL.h>

namespace Kokiri {
    namespace Core {
        Game::Game(const std::string& title, int width, int height) {
            using namespace Graphics::OpenGL;
            using namespace Graphics::SDL;

            if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
                Log::error("failed to initialize SDL2 subsystems, reason ", SDL_GetError());
                exit(1);
            }

            m_properties = GameProperties{
                .is_running = true,
                .is_fullscreen = false,
                .is_debug = false,

                .fps = 0,
                .target_fps = 60,

                .target_frame_time = 1000.0 / 60,

                .width = width,
                .height = height,
            };

            auto window_properties = Window::WindowProperties{
                .width = width,
                .height = height,
                //.flags = SDL_WINDOW_OPENGL,
                .flags = 0,

                .title = title
            };

            m_sound = make_scope_ref<Sound>();
            m_event = make_scope_ref<Event>();
            m_window = make_shared_ref<Window>(window_properties);
            //m_renderer = make_scope_ref<Renderer2D>(m_window);
            m_sdl_renderer = make_scope_ref<Renderer>();

            //m_renderer->information();
        }

        Game::~Game() {}

        void Game::init(std::function<void()> init) {
            init();
        }

        void Game::update(std::function<void(double)> update) {}

        void Game::render(std::function<void()> render) {
            int r = SDL_RenderClear(m_window.get()->get_renderer());
            if (r < 0) {
                Log::error("failed to render clear, reason ", SDL_GetError());
            }

            // call the user provided render function;
            render();

            SDL_RenderPresent(m_window.get()->get_renderer());
        }

        void Game::event(std::function<void()> event) {
            auto e = m_event.get()->event;

            SDL_PollEvent(&e);

            switch (e.type) {
            case SDL_QUIT:
                m_properties.is_running = false;
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                case SDLK_ESCAPE:
                case SDLK_q:
                    m_properties.is_running = false;
                    break;
                case SDLK_F1:
                    m_properties.is_debug = !m_properties.is_debug;
                }
            }

            if (m_properties.is_debug) {
                Core::Log::info("event ", e.type);
            }
        }

        void Game::loop() {
            double dt = 0.0;

            while (m_properties.is_running) {
                Timer t;

                render([](){});
                event([](){});
                update([&dt](double delta){});

                auto since = t.since(Timer::Unit::Milliseconds);

                if (m_properties.is_debug) {
                    Log::info("render time ", since, "ms");
                }

                /*

                 if (since < m_properties.target_frame_time) {
                    auto difference = m_properties.target_frame_time - since;
                    auto delay = std::chrono::duration_cast<Timer::Milliseconds>(difference);

                    std::this_thread::sleep_for(delay);
                } */

                // Doesn't work for some reason (for now)
                //m_renderer.get()->swap_buffers(m_window);

                // To be used with an OpenGL window context
                //SDL_GL_SwapWindow(m_window.get()->get_window());
            }
        }

        void Game::quit() {
            // this code is not to be called from within a library as the
            // documentation prescribes.
            SDL_Quit();
        }

        SharedRef<Window> Game::get_window() {
            return m_window;
        }
    }
}