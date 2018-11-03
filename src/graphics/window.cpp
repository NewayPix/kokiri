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

#include "window.hpp"

Window::Window(int width, int height, const std::string &title, int32_t flags) {

    m_window = nullptr;
    m_window_renderer = nullptr;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        Debug::log_err("Failed to initialize SDL2 video system. Reason: ",
                       SDL_GetError());
        exit(1);
    }

    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, width, height, flags);

    if (m_window == nullptr) {
        Debug::log_err("Failed to initialize window");
        Debug::log_err("Reason: ", SDL_GetError());
        exit(1);
    }

    m_window_renderer = SDL_CreateRenderer(m_window, -1,
                                           SDL_RENDERER_ACCELERATED);

    if (m_window_renderer == nullptr) {
        Debug::log_err("Failed to initialize renderer");
        Debug::log_err("Reason: ", SDL_GetError());
        exit(1);
    }
}

Window::~Window() {
    Debug::log("Destroying Renderer");
    SDL_DestroyRenderer(m_window_renderer);
    Debug::log("Destroying Window");
    SDL_DestroyWindow(m_window);
}

SDL_Window *Window::get_window() {
    return m_window;
}

SDL_Renderer *Window::get_renderer() {
    return m_window_renderer;
}
