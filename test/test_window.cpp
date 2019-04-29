/**
 * MIT License
 *
 * Copyright (c) 2018 Rafael C. Nunes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE  SOFTWARE.
 */

#include <iostream>
#include <cstdint>

#include <SDL2/SDL.h>

#include <glad/glad.h>

#include "graphics/window.hpp"
#include "graphics/renderer.hpp"
#include "utils/debug/debug.hpp"

/**
 * @brief Prints the usage of the renderer.
 */
void usage();

int main(int argc, char *argv[]) {

    bool running = true;
    bool debug = false;
    SDL_Event event;

    uint32_t frame = 0;
    uint32_t fps = 60;

    Window window(800, 600, "Kokiri Framework",
                  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    OpenGLRenderer renderer = OpenGLRenderer(std::move(window));

    while (running) {
        frame = SDL_GetTicks();

        SDL_PollEvent(&event);

        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            /**
             * This is synchronous state.
             */
            switch(event.key.keysym.sym) {
            case SDLK_UP:
                //renderer.rotate(2, -1, 0, 0);
                break;
            case SDLK_DOWN:
                //renderer.rotate(2, 1, 0, 0);
                break;
            case SDLK_LEFT:
                //renderer.rotate(2, 0, -1, 0);
                break;
            case SDLK_RIGHT:
                //renderer.rotate(2, 0, 1, 0);
                break;
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

        renderer.render_view();

        SDL_GL_SwapWindow(window.get_window());

        double delay = 1000/fps-(SDL_GetTicks()-frame);

        if (1000/fps > (SDL_GetTicks() - frame)) {
            SDL_Delay(delay);
        }

#ifdef DEBUG
        Debug::log("Delay: ", delay);
#endif // DEBUG
    }

    Debug::log("Exiting SDL2");
    SDL_Quit();

    return 0;
}
<<<<<<< HEAD:test/test_window.cpp
=======

void usage() {
    std::cerr << ERROR_COLOR
              << "This program should be run with one of the current ways:\n"
              << "\n";
#ifdef __WIN32__
    std::cerr << "\t1) kokiri.exe <path_to_object.obj>\n"
              << "\t2) kokiri.exe";
#else
    std::cerr << "\t1) kokiri.out <path_to_object.obj>\n"
              << "\t2) kokiri.out";
#endif
    std::cerr << RESET_COLOR << std::endl;
}
>>>>>>> 9d7b62f (Remove the primitives files):src/main.cpp
