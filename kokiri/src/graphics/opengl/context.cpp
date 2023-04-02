#include "kkr.hpp"
#include "context.hpp"

#include <glad/glad.h>

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            Context::Context(Window&& window, ContextType context, ContextVersion version) {

                int major = 2;
                int minor = 0;

                if (version == ContextVersion::OPENGL_3_1) {
                    major = 3;
                    minor = 1;
                } else if (version == ContextVersion::OPENGL_3_2) {
                    major = 3;
                    minor = 2;
                } else if (version == ContextVersion::OPENGL_4_0) {
                    major = 4;
                } else if (version == ContextVersion::OPENGL_4_5) {
                    major = 4;
                    minor = 5;
                } else if (version == ContextVersion::OPENGL_4_6) {
                    major = 4;
                    minor = 6;
                }

                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);

                if (context == ContextType::COMPABILITY) {
                    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
                } else {
                    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
                }

                m_context = SDL_GL_CreateContext(window.get_window());

                if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
                    // TODO: Improve error message
                    Core::Log::error("failed to create OpenGL context");
                    exit(1);
                }
            }

            Context::~Context() {
                Core::Log::info("destroying OpenGL Context");
                SDL_GL_DeleteContext(m_context);
            }

            SDL_GLContext *Context::get_context() {
                return &m_context;
            }
        }
    }
}