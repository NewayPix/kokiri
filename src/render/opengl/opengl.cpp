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

#include "opengl.hpp"

#include "../3rd/glad/glad.h"
#include "../core/debug/debug.hpp"


OpenGLRenderer::OpenGLRenderer(Window &&window) : Render(std::move(window)) {
    
    m_context = new OpenGLContext(std::move(window),
                                  OpenGLContext::OGLContextType::CORE);
}

OpenGLRenderer::OpenGLRenderer(Window &&window, OpenGLContext::OGLVersion version) : Render(std::move(window)) {

    m_context = new OpenGLContext(std::move(window),
                                  OpenGLContext::OGLContextType::CORE, version);
}

OpenGLRenderer::~OpenGLRenderer() {
    delete m_context;
}


void OpenGLRenderer::information() {
    Debug::log("Plataform: ", SDL_GetPlatform());
    Debug::log("OpenGL version: ", glGetString(GL_VERSION));
    Debug::log("OpenGL vendor: ", glGetString(GL_VENDOR));
    Debug::log("OpenGL renderer: ", glGetString(GL_RENDERER));
#if !__WIN32__
    Debug::log("GLSL version: ", glGetString(GL_SHADING_LANGUAGE_VERSION));
#endif // not adding more headers just to have this working, for now.
}
