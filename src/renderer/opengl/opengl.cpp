#include "kkr.hpp"
#include "opengl.hpp"


OpenGLRenderer::OpenGLRenderer(Window &&window) : Renderer(std::move(window)) {
    m_context = new OpenGLContext(std::move(window), OpenGLContext::OGLContextType::CORE);
}

OpenGLRenderer::OpenGLRenderer(Window &&window, OpenGLContext::OGLVersion version) : Renderer(std::move(window)) {
    m_context = new OpenGLContext(std::move(window), OpenGLContext::OGLContextType::CORE, version);
}

OpenGLRenderer::~OpenGLRenderer() {
    delete m_context;
}


void OpenGLRenderer::information() {
    Log::info("Plataform: ", SDL_GetPlatform());
    Log::info("OpenGL version: ", glGetString(GL_VERSION));
    Log::info("OpenGL vendor: ", glGetString(GL_VENDOR));
    Log::info("OpenGL renderer: ", glGetString(GL_RENDERER));
#if !__WIN32__
    Log::info("GLSL version: ", glGetString(GL_SHADING_LANGUAGE_VERSION));
#endif // not adding more headers just to have this working, for now.
}
