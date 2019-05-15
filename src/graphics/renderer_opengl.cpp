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

#include "renderer_opengl.hpp"

#include "../3rd/glad/glad.h"
#include "../utils/debug/debug.hpp"


OpenGLRenderer::OpenGLRenderer(Window &&window) : Renderer(std::move(window)) {

    // Creates an OpenGL context for drawing
    m_context = new OpenGLContext(std::move(window),
                              OpenGLContext::OGLContextType::CORE);

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

OpenGLRenderer::~OpenGLRenderer() {
    delete m_context;
}

void OpenGLRenderer::render_view() {
    glClearColor(0.3, 0.5, 0.9, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

void OpenGLRenderer::render(Object object) {
    glBufferData(GL_ARRAY_BUFFER, object.vertices.size() * sizeof(glm::vec3),
                 &object.vertices[0], GL_STATIC_DRAW);
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
