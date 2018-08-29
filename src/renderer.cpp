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

#include "renderer.hpp"

#include "graphics/primitives.hpp"

Renderer::Renderer(SDL_GLContext& gl_context) {
    // making _renderer point to a copy of the renderer pointer.
    _gl_context = gl_context;

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 800/600, 1, 500.0);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    // Position of the light
    float gl_light_pos[] = {-2.0, 2.0, 1.0};
    // Diffuse light
    float diffuse_light[] = {1.0, 1.0, 1.0, 1.0};
    // Ambient light intensity
    float ambient_light[] = {0.2, 0.2, 0.2, 0.2};
    // Setting a light1
    glLightfv(GL_LIGHT0, GL_POSITION, gl_light_pos);
    //Setting the diffuse light
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    //Setting ambient light
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);

    glTranslatef(0.0, 0.0, -3.0);
}

void Renderer::render_cube(float size) {
    glClearColor(0.3, 0.3, 0.3, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // not used here
    float material_light[] = {0.2, 0.2, 0.2, 0.2};

    Primitives::cube(size);
}

void Renderer::render(Object object) {
    //glBufferData(GL_ARRAY_BUFFER, object.vertices.size() * sizeof(Vector3<int>),
    //             &object.vertices[0], GL_STATIC_DRAW);
}

void Renderer::rotate(float angle, float x, float y, float z) {
    glRotatef(angle, x, y, z);
}

void Renderer::rotate(float angle, Vector3<float> v) {
    glRotatef(angle, v.m_x, v.m_y, v.m_z);
}
