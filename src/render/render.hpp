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

#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include <SDL2/SDL.h>
#include <glad/glad.h>

// FIXME: Using glu while not using the glm implementation of the camera
#include <GL/glu.h>

#ifdef __WIN32__
    #include <GL/glext.h>
#endif

#include "window.hpp"

/**
 * @brief An abstract class that serves as a starting point for renderers, the
 * basic API is down below, anything that is common to all renderers will have
 * its place here.
 */
class Render {
public:
    /**
     * @brief Initializes the renderer with an OpenGL context.
     */
    Render(Window &&window);
    virtual ~Render();

    /**
     * @brief
     */
    virtual void information();
};

#endif // OPENGL_RENDERER_HPP
