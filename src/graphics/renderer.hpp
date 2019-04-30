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

// This is ugly but I have to use for a while
#include "../maths/vector3.hpp"
#include "../utils/object.hpp"

/**
 * @brief
 */
class Renderer {
private:
    SDL_GLContext m_gl_context;
public:
    /**
     * @brief Creates a renderer with an OpenGL context.
     * @param gl_context
     */
    Renderer(Window&& window);
    ~Renderer();

    /**
     * @brief Writes information about the renderer on the default stdout.
     */
    void information();

    /**
     * @brief Renders the render view GUI.
     * TODO: Should be moved to a UI module.
     */
    void render_view();

    /**
     * @brief Renders any kind of the object.
     * @param obj The object to be rendered.
     */
    void render(Object obj);

    /**
     * @brief Rotates the object being rendered in the x, y, z direction
     * by angle angles.
     * @param angle
     * @param x
     * @param y
     * @param z
     */
    void rotate(float angle, float x, float y, float z);
    /**
     * @brief Rotates the object being rendered in the v direction.
     * @param angle
     * @param v
     */
    void rotate(float angle, Vector3<float> v);
};

#endif // OPENGL_RENDERER_HPP
