#pragma once

#include <SDL2/SDL.h>

#include "../window.hpp"

/**
 * @brief Represents an OpenGL context within the engine. It holds an instance
 * to SDL_GLContext and has a lot of utilities to choose the right version to
 * init the context.
 */
class OpenGLContext {
private:
    // A handler to the OpenGL context
    SDL_GLContext m_context;

public:
    /// Current available types of context that cold be created.
    enum class OGLContextType {
        CORE,
        COMPABILITY
    };

    /// Describe the current version of OpenGL versions that could be used to
    /// create the context.
    enum class OGLVersion {
        OPENGL_3_1,
        OPENGL_3_2,
        OPENGL_4_0,
        OPENGL_4_5
    };

    /**
     * @brief Constructs a context according to the specified version of profile
     * and version.
     *
     * @param window A universal reference to a window
     * @param context
     * @param version
     */
    OpenGLContext(Window &&window, OGLContextType context, OGLVersion version = OGLVersion::OPENGL_3_1);
    ~OpenGLContext();

    /**
     * @brief Returns a pointer to an OpenGL context which of type SDL_GLContext
     */
    SDL_GLContext *get_context();
};