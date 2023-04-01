#pragma once

#include <string>

#include <glad/glad.h>

#ifdef __WIN32__
#include <GL/glext.h>
#else
#include <glm/glm.hpp>
#endif

/**
 * @brief The Shader class represents a resource that is used in the OpenGL
 * pipeline in order to provide post rendering effects. The shader can be of
 * these three main types:
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
    GLuint m_handle;

    /// The source code of the shader
    std::string m_source;

public:
    /**
     * @brief Constructs the shader of a shader_type param
     * @param code The source code of the shader
     * @param shader_type The type of the shader, which can vary from
     *  fragment, vertex and volume shader.
     */
    Shader(const std::string &code, GLenum  shader_type);
    virtual ~Shader();

    std::string get_source_code() const;

    GLuint get_handle() const;
};