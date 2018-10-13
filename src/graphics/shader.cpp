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

#include "shader.hpp"

#include "../utils/debug/debug.hpp"

Shader::Shader(const std::string &shader, GLenum shader_type) : code(shader) {
    // TODO: Change this for the choosen enum
    handle = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(handle, 1, &shader.c_str(),  nullptr);
    glCompileShader(handle);

    // Change this for exceptions and get all possible errors that can occur.
    if (glGetError() != GL_NO_ERROR) {
        log_err("Something wen't wront while compiling the shader: ",
                shader_type);
    }
}

GLuint Shader::get_handle() const {
    return handle;
}
