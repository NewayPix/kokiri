#pragma once

#include <SDL2/SDL.h>
#include <glad/glad.h>

// FIXME: Using glu while not using the glm implementation of the camera
#include <GL/glu.h>

#ifdef __WIN32__
    #include <GL/glext.h>
#endif

#include "window.hpp"

/**
 * @brief An abstract class that serves as a starting point for renderers, the
 * basic API is down below, anything that is common to all renderers will have
 * its place here.
 */
class Renderer {
public:
    /**
     * @brief Initializes the renderer with an OpenGL context.
     */
    Renderer(Window &&window);
    virtual ~Renderer();

    /**
     * @brief
     */
    virtual void information();
};