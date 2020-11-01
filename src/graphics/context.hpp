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

#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H

#include <SDL2/SDL.h>

#include "window.hpp"

/**
 * @brief Represents an OpenGL context within the engine. It holds an instance
 * to SDL_GLContext and has a lot of utilities to choose the right version to
 * init the context.
 */
class OpenGLContext {
private:
    // A handler to the OpenGL context
    SDL_GLContext m_context;

public:
    /// Current available types of context that cold be created.
    enum class OGLContextType {
        CORE,
        COMPABILITY
    };

    /// Describe the current version of OpenGL versions that could be used to
    /// create the context.
    enum class OGLVersion {
        OPENGL_3_1,
        OPENGL_3_2,
        OPENGL_4_0,
        OPENGL_4_5
    };

    /**
     * @brief Constructs a context according to the specified version of profile
     * and version.
     *
     * @param window A universal reference to a window
     * @param context
     * @param version
     */
    OpenGLContext(Window &&window, OGLContextType context,
                  OGLVersion version = OGLVersion::OPENGL_3_1);
    ~OpenGLContext();

    /**
     * @brief Returns a pointer to an OpenGL context which of type SDL_GLContext
     */
    SDL_GLContext *get_context();
};

#endif // OPENGL_CONTEXT_H
