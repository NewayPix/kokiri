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

#include <GL/gl.h>
#include <GL/glu.h>

#include <cmath>

#include "primitives.hpp"


// Quick fix for a while, some extended math library has to be written in order
// to provide some extensions.
#ifndef M_PI
#define M_PI 3.141592653589793 // defined as acos(-1.0)
#endif // M_PI

void Primitives::cube(float size) {

    glBegin(GL_QUADS);
    // front face
    glNormal3f(0, 0, 1);
    glVertex3f(size/2,size/2,size/2);
    glVertex3f(-size/2,size/2,size/2);
    glVertex3f(-size/2,-size/2,size/2);
    glVertex3f(size/2,-size/2,size/2);

    // left face
    glNormal3f(-1, 0, 0);
    glVertex3f(-size/2,size/2,size/2);
    glVertex3f(-size/2,-size/2,size/2);
    glVertex3f(-size/2,-size/2,-size/2);
    glVertex3f(-size/2,size/2,-size/2);

    // back face
    glNormal3f(0, 0, -1);
    glVertex3f(size/2,size/2,-size/2);
    glVertex3f(-size/2,size/2,-size/2);
    glVertex3f(-size/2,-size/2,-size/2);
    glVertex3f(size/2,-size/2,-size/2);

    // right face
    glNormal3f(1, 0, 0);
    glVertex3f(size/2,size/2,size/2);
    glVertex3f(size/2,-size/2,size/2);
    glVertex3f(size/2,-size/2,-size/2);
    glVertex3f(size/2,size/2,-size/2);

    // top face
    glNormal3f(0, 1, 0);
    glVertex3f(size/2,size/2,size/2);
    glVertex3f(-size/2,size/2,size/2);
    glVertex3f(-size/2,size/2,-size/2);
    glVertex3f(size/2,size/2,-size/2);

    // bottom face
    glNormal3f(0, -1, 0);
    glVertex3f(size/2,-size/2,size/2);
    glVertex3f(-size/2,-size/2,size/2);
    glVertex3f(-size/2,-size/2,-size/2);
    glVertex3f(size/2,-size/2,-size/2);
    glEnd();
}

void Primitives::sphere(float radius) {

    float partition_angle = 2*M_PI/360;

    for (int i = 0; i < 360; i++) {
        glBegin(GL_LINES);
        for (int j = 0; j < 180; j++) {
            float x = radius*cos(partition_angle*i)*sin(partition_angle*j);
            float y = radius*sin(partition_angle*i)*sin(partition_angle*j);
            float z = radius*cos(partition_angle*j);

            glVertex3f(x, y, z);
        }
        glEnd();
    }
}

void Primitives::tetrahedron(float length) {

    glBegin(GL_TRIANGLES);
    // front side face
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, length/2);
    glVertex3d(length/2, 0, 0);

    // bottom face
    glVertex3d(0, 0, 0);
    glVertex3d(0, length/2, 0);
    glVertex3d(0, 0, length/2);

    // back side face
    glVertex3d(0, 0, 0);
    glVertex3d(0, length/2, 0);
    glVertex3d(length/2, 0, 0);

    // left side face
    glVertex3d(0, 0, length/2);
    glVertex3d(0, length/2, 0);
    glVertex3d(length/2, 0, 0);
    glEnd();

}

void Primitives::cone(float height, float radius) {

    float partition_angle = 2*M_PI/360;

    // circumference + a line from each point of the circle to a top vertex
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float x = radius*cos(partition_angle*i)/2;
        float z = radius*sin(partition_angle*i)/2;

        glVertex3f(x, 0, z);
    }
    glEnd();

    partition_angle = 2*M_PI/720;

    glBegin(GL_LINES);
    for (int i = 0; i < 720; i++) {
        float x = radius*cos(partition_angle*i)/2;
        float z = radius*sin(partition_angle*i)/2;

        glVertex3f(x, 0, z);
        glVertex3f(0, height, 0);
    }
    glEnd();
}

void Primitives::triangle() {

    glBegin(GL_TRIANGLES);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
        glVertex2f(0.0, 2.0);
    glEnd();
}
