#include <iostream>
#include <cstdint>

#include "graphics/window.hpp"
#include "graphics/renderer.hpp"
#include "utils/debug/debug.hpp"
#include "graphics/renderer_opengl.hpp"

int main(int argc, char *argv[]) {

    bool running = true;
    bool debug = false;
    SDL_Event event;

    Window window(800, 600, "Kokiri Framework",
                  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    OpenGLRenderer renderer = OpenGLRenderer(std::move(window));

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
