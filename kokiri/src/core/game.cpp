#include "kkr.hpp"
#include "game.hpp"
#include "timer.hpp"

#include <SDL2/SDL.h>

namespace Kokiri {
    Game::Game(const std::string& title, int width, int height) {
        using namespace Graphics;

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
        m_event = make_shared_ref<Event>();
        m_window = make_shared_ref<Window>(window_properties);
        m_opengl_renderer = make_scope_ref<OpenGL::Renderer2D>(m_window);
        m_sdl_renderer = make_scope_ref<SDL::Renderer2D>(m_window);

        //m_opengl_renderer->information();
    }

    Game::~Game() {}

    void Game::init() {
    }

    void Game::update() {}

    void Game::render() {
        int r = SDL_RenderClear(m_window.get()->get_renderer());
        if (r < 0) {
            Log::error("failed to render clear, reason ", SDL_GetError());
        }

        // call the user provided render function
        try {
            auto r = m_functions.at(FunctionType::Render);
            r();
        } catch (const std::exception& ex) {
            // do nothing... on purpose
        }

        SDL_RenderPresent(m_window.get()->get_renderer());
    }

    void Game::event() {
        auto e = m_event.get();

        e->pool();

        if (e->quit()) {
            m_properties.is_running = false;
        }

        if (e->is_key_down(Event::Key::Q) || e->is_key_down(Event::Key::ESC)) {
            m_properties.is_running = false;
        }
        if (e->is_key_down(Event::Key::F1)) {
            m_properties.is_debug = !m_properties.is_debug;
        }

        if (m_properties.is_debug) {
            Log::info("event happened");
        }

        {
            // call the user provided event function
            try {
                auto e = m_functions.at(FunctionType::Event);
                e();
            } catch (const std::exception& ex) {
                // do nothing... on purpose
            }
        }
    }

    void Game::loop() {
        double dt = 0.0;

        while (m_properties.is_running) {
            Timer t;

            render();
            event();
            update();

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
            //m_opengl_renderer.get()->swap_buffers(m_window);

            // To be used with an OpenGL window context
            //SDL_GL_SwapWindow(m_window.get()->get_window());
        }
    }

    void Game::quit() {
        // this code is not to be called from within a library as the
        // documentation prescribes.
        SDL_Quit();
    }

    void Game::bind(FunctionType type, Function<void> function) {
        m_functions.emplace(type, function);
    }

    SharedRef<Window> Game::get_window() {
        return m_window;
    }

    SharedRef<Event> Game::get_event() {
        return m_event;
    }
}