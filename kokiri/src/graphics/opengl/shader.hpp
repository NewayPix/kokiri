#pragma once

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            /**
             * @brief The Shader class represents a resource that is used in the OpenGL
             * pipeline in order to provide post rendering effects. The shader can be of
             * these three main types:
             * 1. Fragment shader
             * 2. Vertex shader
             * 3. Volume shader
             * 4. Compute shader
             *
             * The first two are quite used on most applications and the are available
             * through GL_<SHADER_TYPE>_SHADER.
             */
            class Shader {
            private:
                /// The handle that represents the shader
                GLuint m_handle;

                /// The source code of the shader
                std::string m_source;

            public:
                enum class ShaderType {
                    VERTEX = GL_VERTEX_SHADER,
                    FRAGMENT = GL_FRAGMENT_SHADER,
                    COMPUTE = 0xFFFF,
                };

                /**
                 * @brief Constructs the shader of a shader_type param
                 * @param code The source code of the shader
                 * @param shader_type The type of the shader, which can vary from
                 *  fragment, vertex and volume shader.
                 */
                Shader(const std::string &code, ShaderType type);
                ~Shader();

                /**
                 * @brief Get the source code of the shader object
                 *
                 * @return std::string the source code
                 */
                std::string get_source() const;

                GLuint get_handle() const;
            };
        }
    }
}