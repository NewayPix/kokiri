#include "kkr.hpp"
#include "renderer2d.hpp"

#include <glad/glad.h>

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            Renderer2D::Renderer2D(const SharedRef<Window>& window) {
                auto type = Type::CORE;
                auto version = Version::OPENGL_4_6;

                int major = m_version.at(version).first;
                int minor = m_version.at(version).second;

                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);

                if (type == Type::COMPABILITY) {
                    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
                } else {
                    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
                }

                auto context = SDL_GL_CreateContext(window.get()->get_window());

                m_context = make_shared_ref<SDL_GLContext>(context);

                if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
                    // TODO: Improve error message
                    Log::error("failed to create OpenGL context");
                    exit(1);
                }
            }

            Renderer2D::~Renderer2D() {
                Log::info("destroying OpenGL context");
                SDL_GL_DeleteContext(m_context.get());
            }

            void Renderer2D::draw() {

            }

            void swap_buffers(const SharedRef<Window>& window) {
                SDL_GL_SwapWindow(window.get()->get_window());
            }

            void Renderer2D::information() {
                Log::info("Plataform: ", SDL_GetPlatform());
                Log::info("OpenGL version: ", glGetString(GL_VERSION));
                Log::info("OpenGL vendor: ", glGetString(GL_VENDOR));
                Log::info("OpenGL renderer: ", glGetString(GL_RENDERER));
            #if !__WIN32__
                Log::info("GLSL version: ", glGetString(GL_SHADING_LANGUAGE_VERSION));
            #endif // not adding more headers just to have this working, for now.
            }
        }
    }
}