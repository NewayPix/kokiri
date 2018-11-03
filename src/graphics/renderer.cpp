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
#include "primitives.hpp"

#include "../utils/debug/debug.hpp"

Renderer::Renderer(SDL_GLContext& gl_context) {

    // making _renderer point to a copy of the renderer pointer.
    m_gl_context = gl_context;

    // Before constructing the OpenGL context set the GL attributes.
    // TODO: Create an interface to change this (it depends on glad as well).
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        // TODO: Improve error message
        Debug::log_err("OpenGL context couldn't be created");
        exit(1);
    }

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

Renderer::~Renderer() {
    Debug::log("Destroying OpenGL Context");
    SDL_GL_DeleteContext(m_gl_context);
}

void Renderer::information() {

    Debug::log("Plataform: ", SDL_GetPlatform());
    Debug::log("OpenGL version: ", glGetString(GL_VERSION));
    Debug::log("OpenGL vendor: ", glGetString(GL_VENDOR));
    Debug::log("OpenGL renderer: ", glGetString(GL_RENDERER));
#if !__WIN32__
    Debug::log("GLSL version: ", glGetString(GL_SHADING_LANGUAGE_VERSION));
#endif // not adding more headers just to have this working, for now.
}

void Renderer::render_view() {

    glClearColor(0.3, 0.5, 0.9, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // need the width and the height of the screen for grid lines
    /*glColor3f(255, 255, 255);
    for (int i = 0; i < 800; i += 5) {
        glBegin(GL_LINES);
        glVertex2d(-1000, i);
        glVertex2d(1000, i);
        glEnd();
    }
    for (int i = 0; i < 600; i += 5) {
        glBegin(GL_LINES);
        glVertex2d(i, -1000);
        glVertex2d(i, 1000);
        glEnd();
    }*/

    // Axis lines
    glColor3f(255, 0, 0);
    glBegin(GL_LINES);
    glVertex3d(0, 0, 0);
    glVertex3d(2, 0, 0);
    glEnd();

    glColor3f(0, 255, 0);
    glBegin(GL_LINES);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 2, 0);
    glEnd();

    glColor3f(0, 0, 255);
    glBegin(GL_LINES);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, 2);
    glEnd();

    glColor3f(120, 120, 120);
}

void Renderer::render(Object object) {
    glBufferData(GL_ARRAY_BUFFER, object.vertices.size() * sizeof(glm::vec3),
                 &object.vertices[0], GL_STATIC_DRAW);
}

void Renderer::rotate(float angle, float x, float y, float z) {
    glRotatef(angle, x, y, z);
}

void Renderer::rotate(float angle, Vector3<float> v) {
    glRotatef(angle, v.m_x, v.m_y, v.m_z);
}
