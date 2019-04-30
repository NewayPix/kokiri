/**
 * MIT License
 *
<<<<<<< HEAD
 * Copyright (c) 2018 Rafael C. Nunes
=======
 * Copyright (c) 2019 Rafael C. Nunes
>>>>>>> b432674 (Remove any references of the old primitives)
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

#include "renderer.hpp"

#include "../utils/debug/debug.hpp"

Renderer::Renderer(Window&& window) {
    // making _renderer point to a copy of the renderer pointer.
    m_gl_context = SDL_GL_CreateContext(window.get_window());

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        // TODO: Improve error message
        Debug::log_err("OpenGL context couldn't be created");
        exit(1);
    }
}

void Renderer::render_view() {}

void Renderer::information() {}
