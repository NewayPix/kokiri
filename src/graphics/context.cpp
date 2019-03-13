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

#include "../3rd/glad/glad.h"

#include "context.hpp"
#include "../utils/debug/debug.hpp"

OpenGLContext::OpenGLContext(Window&& window, OGLContextType context,
                             OGLVersion version) {

    int major = 2;
    int minor = 0;

    if (version == OGLVersion::OPENGL_3_0) {
        major = 3;
    } else if (version == OGLVersion::OPENGL_4_0) {
        major = 4;
    } else if (version == OGLVersion::OPENGL_4_5) {
        major = 4;
        minor = 5;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);


    if (context == OGLContextType::COMPABILITY) {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                            SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    } else {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                            SDL_GL_CONTEXT_PROFILE_CORE);
    }

    m_context = SDL_GL_CreateContext(window.get_window());

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        // TODO: Improve error message
        Debug::log_err("OpenGL context couldn't be created");
        exit(1);
    }
}

OpenGLContext::~OpenGLContext() {
    Debug::log("Destroying OpenGL Context");
    SDL_GL_DeleteContext(m_context);
}

SDL_GLContext *OpenGLContext::get_context() {
    return &m_context;
}
