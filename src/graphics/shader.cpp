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
