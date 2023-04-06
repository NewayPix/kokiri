#include <iostream>
#include <cstdint>

#include "core/debug/log.hpp"
#include "core/window.hpp"

#include "graphics/opengl/renderer2d.hpp"

int main(int argc, char *argv[]) {
    using namespace Kokiri::Core;
    using namespace Kokiri::Graphics;
    using namespace Kokiri::Graphics::OpenGL;

    bool is_running = true;
    bool is_fullscreen = false;
    bool debug = false;

    SDL_Event event;

    Window window(800, 600, "Kokiri Framework", SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    auto renderer = Renderer2D(std::move(window), Renderer2D::Version::OPENGL_4_6);

    renderer.information();

    while (is_running) {
        SDL_PollEvent(&event);

        switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {
            case SDLK_ESCAPE:
                is_running = false;
                break;
            case SDLK_d:
                debug = !debug;
                break;
            case SDLK_f:
                {
                    is_fullscreen = !is_fullscreen;

                    int state = 0;

                    if (is_fullscreen) {
                        state = SDL_SetWindowFullscreen(window.get_window(), SDL_WINDOW_FULLSCREEN);
                    } else {
                        state = SDL_SetWindowFullscreen(window.get_window(), 0);
                    }

                    if (state < 0) {
                        Log::error("failed to toggle fullscreen, reason ", SDL_GetError());
                    }
                }
                break;
            default:
#ifdef DEBUG
                Log::info("event: ", event.type);
#endif // DEBUG
                break;
            }
        }

        SDL_GL_SwapWindow(window.get_window());
    }

    SDL_Quit();

    return 0;
}
