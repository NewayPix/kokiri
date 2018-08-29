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

#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include <SDL2/SDL.h>

#include <GL/gl.h>
#include <GL/glu.h>

#ifdef __WIN32__
    #include <GL/glext.h>
    #include <glm.hpp>
#endif

#include "maths/vector3.hpp"
#include "object.hpp"

class Renderer {
private:
    SDL_GLContext _gl_context;
public:
    /**
     * @brief Creates a renderer with an OpenGL context.
     * @param gl_context
     */
    Renderer(SDL_GLContext& gl_context);
    ~Renderer() {};

    /**
     * @brief Renders a cube of any size.
     * @param size The optional size of the cube to be rendered.
     */
    void render_cube(float size = 1.8);

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
