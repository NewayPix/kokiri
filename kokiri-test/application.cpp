#include <iostream>
#include <cstdint>

#include "core/debug/log.hpp"
#include "graphics/window.hpp"
#include "graphics/opengl/renderer2d.hpp"

int main(int argc, char *argv[]) {

    bool running = true;
    bool debug = false;
    SDL_Event event;

    Kokiri::Graphics::Window window(800, 600, "Kokiri Framework", SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    auto renderer = Kokiri::Graphics::OpenGL::Renderer2D(std::move(window), Kokiri::Graphics::OpenGL::Context::ContextVersion::OPENGL_4_6);

    renderer.information();

    while (running) {
        SDL_PollEvent(&event);

        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {
            case SDLK_ESCAPE:
                running = false;
                break;
            case SDLK_d:
                debug = !debug;
                break;
            default:
#ifdef DEBUG
                std::cout << "Event: " << event.type << std::endl;
#endif // DEBUG
            break;
            }
        }

        SDL_GL_SwapWindow(window.get_window());
    }

    SDL_Quit();

    return 0;
}
