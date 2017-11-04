/**
 * MIT License
 *
 * Copyright (c) 2016 Rafael C. Nunes
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

#include "debug.hpp"
#include "renderer.hpp"

int main(int argc, char **argv) {

    bool running = true;
    bool debug = false;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Event event;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        Debug::log_err("Failed to initialize SDL2 video system. Reason: ",
                       SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Object Renderer", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, 800, 600,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        Debug::log_err("Failed to initialize window");
        Debug::log_err("Reason: ", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        Debug::log_err("Failed to initialize renderer");
        Debug::log_err("Reason: ", SDL_GetError());
        return 1;
    }

    SDL_GLContext gl = SDL_GL_CreateContext(window);
    // Send the gl context to the renderer
    Renderer opengl_renderer = Renderer(gl);

    uint32_t frame = 0;
    uint32_t fps = 60;

    Debug::log("OpenGL version: ", glGetString(GL_VERSION));
    Debug::log("OpenGL vendor: ", glGetString(GL_VENDOR));
    Debug::log("OpenGL renderer: ", glGetString(GL_RENDERER));
#if !__WIN32__
    Debug::log("GLSL version: ", glGetString(GL_SHADING_LANGUAGE_VERSION));
#endif // not adding more headers just to have this working, for now.

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
                opengl_renderer.rotate(2, -1, 0, 0);
                break;
            case SDLK_DOWN:
                opengl_renderer.rotate(2, 1, 0, 0);
                break;
            case SDLK_LEFT:
                opengl_renderer.rotate(2, 0, -1, 0);
                break;
            case SDLK_RIGHT:
                opengl_renderer.rotate(2, 0, 1, 0);
                break;
            case SDLK_ESCAPE:
                running = false;
                break;
            case SDLK_d:
                debug = !debug;
                break;
            }
        default:
#ifdef DEBUG
            std::cout << "Event: " << event.type << std::endl;
#endif // DEBUG
            break;
        }

        //opengl_renderer.rotate(1, 1, 1, 0);
        opengl_renderer.render_cube(2.0);
        SDL_GL_SwapWindow(window);

        double delay = 1000/fps-(SDL_GetTicks()-frame);

        if (1000/fps > (SDL_GetTicks() - frame)) {
            SDL_Delay(delay);
        }

#ifdef DEBUG
            Debug::log("Delay: ", delay);
#endif // DEBUG
    }

    Debug::log("Destroying context/renderer/window");

    SDL_GL_DeleteContext(gl);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Debug::log("Exiting SDL2\n");

    SDL_Quit();

    return 0;
}
