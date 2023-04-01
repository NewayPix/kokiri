#pragma once

#include <GL/glu.h>

#if defined(__WIN32__) || defined(__WIN32) || defined(__MINGW32__)
#include <GL/glext.h>
#endif


#include "context.hpp"

#include "../window.hpp"
#include "../render.hpp"

class OpenGLRenderer : Renderer {
public:
    OpenGLRenderer(Window &&window);
    OpenGLRenderer(Window &&window, OpenGLContext::OGLVersion version);
    ~OpenGLRenderer();

    /**
     * @brief Writes information about the renderer on the default stdout.
     */
    void information() override;
private:
    // An instance of the OpenGLContext which holds all information of the
    // SDL context. One thing that should be noted is that this is not
    // verified to be a good encapsulation at this moment.
    OpenGLContext *m_context;
};
