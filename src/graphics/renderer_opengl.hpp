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

#ifndef RENDERER_OPENGL_H
#define RENDERER_OPENGL_H

#include <glad/glad.h>

#include <GL/glu.h>

#if defined(__WIN32__) || defined(__WIN32) || defined(__MINGW32__)
#include <GL/glext.h>
#endif

#include "window.hpp"
#include "context.hpp"
#include "renderer.hpp"

class OpenGLRenderer : Renderer {
public:
    OpenGLRenderer(Window &&window);
    OpenGLRenderer(Window &&window, OpenGLContext::OGLVersion version);
    ~OpenGLRenderer();

    void render_view() override;
    void render(Object object) override;

    /**
     * @brief Writes information about the renderer on the default stdout.
     */
    void information() override;
private:
    // An instance of the OpenGLContext which holds all information of the
    // SDL context. One thing that should be noted is that this is not
    // verified to be a good encapsulation at this moment.
    OpenGLContext *m_context;
};

#endif // RENDERER_OPENGL_H
