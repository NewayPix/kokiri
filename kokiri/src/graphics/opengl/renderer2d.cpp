#include "kkr.hpp"
#include "renderer2d.hpp"

#include <glad/glad.h>

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            Renderer2D::Renderer2D(Core::SharedRef<Core::Window>& window) {
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

                m_context = Core::make_shared_ref<SDL_GLContext>(context);

                if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
                    // TODO: Improve error message
                    Core::Log::error("failed to create OpenGL context");
                    exit(1);
                }
            }

            Renderer2D::~Renderer2D() {
                Core::Log::info("destroying OpenGL context");
                SDL_GL_DeleteContext(m_context.get());
            }

            void Renderer2D::draw() {

            }

            void swap_buffers(Core::SharedRef<Core::Window>& window) {
                SDL_GL_SwapWindow(window.get()->get_window());
            }

            void Renderer2D::information() {
                Core::Log::info("Plataform: ", SDL_GetPlatform());
                Core::Log::info("OpenGL version: ", glGetString(GL_VERSION));
                Core::Log::info("OpenGL vendor: ", glGetString(GL_VENDOR));
                Core::Log::info("OpenGL renderer: ", glGetString(GL_RENDERER));
            #if !__WIN32__
                Core::Log::info("GLSL version: ", glGetString(GL_SHADING_LANGUAGE_VERSION));
            #endif // not adding more headers just to have this working, for now.
            }
        }
    }
}