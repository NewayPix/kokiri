/**
 * MIT License
 *
 * Copyright (c) 2019 Rafael C. Nunes
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
