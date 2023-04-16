#include "kkr.hpp"
#include "shader.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            Shader::Shader(const std::string &code, ShaderType type) : m_source(code) {
                m_handle = glCreateShader(to_underlying(type));

                // Not sure if this is the way to do it
                const GLchar *const *source = (const GLchar* const *) code.c_str();

                glShaderSource(m_handle, 1, source,  nullptr);
                glCompileShader(m_handle);

                // Change this for exceptions and get all possible errors that can occur.
                if (glGetError() != GL_NO_ERROR) {
                    Log::error("failed to compile shader, reason ", glGetError());
                }
            }

            Shader::~Shader() {
                glDeleteShader(m_handle);
            }


            GLuint Shader::get_handle() const {
                return m_handle;
            }
        }
    }
}