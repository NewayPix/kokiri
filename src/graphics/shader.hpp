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

#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <GL/gl.h>
#include <GL/glu.h>

#include <glm.hpp>

#ifdef __WIN32__
    #include <GL/glext.h>
#endif

/**
 * The Shader class represents a resource that is used in the OpenGL pipeline in
 * order to provide post rendering effects. The shader can be of these three
 * main types:
 * 1. Fragment shader
 * 2. Vertex shader
 * 3. Volume shader
 *
 * The first two are quite used on most applications and the are available
 * through GL_<SHADER_TYPE>_SHADER.
 */
class Shader {
private:
    /// The handle that represents the shader
    GLuint handle;

    /// The source code of the shader
    std::string code;

public:
    Shader(const std::string &shader, GLenum  shader_type);
    virtual ~Shader();

    std::string get_source_code() const;

    GLuint get_handle() const;
};

#endif // SHADER_H
