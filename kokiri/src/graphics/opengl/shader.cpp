#include "kkr.hpp"
#include "shader.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            Shader::Shader(const std::string &code, GLenum shader_type) : m_source(code) {
                // TODO: Change this for the choosen enum
                m_handle = glCreateShader(GL_FRAGMENT_SHADER);

                // Not sure if this is the way to do it
                const GLchar *const *source = (const GLchar* const *) code.c_str();

                glShaderSource(m_handle, 1, source,  nullptr);
                glCompileShader(m_handle);

                // Change this for exceptions and get all possible errors that can occur.
                if (glGetError() != GL_NO_ERROR) {
                    Core::Log::error("failed to compile shader, reason ", shader_type);
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