#include "kkr.hpp"
#include "renderer2d.hpp"

#include <glad/glad.h>

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            Renderer2D::Renderer2D(Window &&window) {
                m_context = new Context(std::move(window), Context::ContextType::CORE);
            }

            Renderer2D::Renderer2D(Window &&window, Context::ContextVersion version) {
                m_context = new Context(std::move(window), Context::ContextType::CORE, version);
            }

            Renderer2D::~Renderer2D() {
                delete m_context;
            }


            void Renderer2D::draw() {

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