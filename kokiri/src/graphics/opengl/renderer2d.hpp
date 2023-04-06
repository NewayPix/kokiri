#pragma once

#if defined(__WIN32__) || defined(__WIN32) || defined(__MINGW32__)
#include <GL/glext.h>
#endif

#include <SDL2/SDL.h>

#include "core/window.hpp"
#include "core/references.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            class Renderer2D {
            private:
                // An instance of the OpenGLContext which holds all information of the
                // SDL context. One thing that should be noted is that this is not
                // verified to be a good encapsulation at this moment.
                Core::Shared<SDL_GLContext> m_context;

            public:
                /// Current available types of context that cold be created.
                enum class Type {
                    CORE,
                    COMPABILITY
                };

                /// Describe the current version of OpenGL versions that could
                /// be used to create the context.
                enum class Version {
                    OPENGL_3_1,
                    OPENGL_3_2,
                    OPENGL_4_0,
                    OPENGL_4_5,
                    OPENGL_4_6,
                };

                Renderer2D(Core::Window &&window);
                Renderer2D(Core::Window &&window, Version version, Type type = Type::CORE);
                ~Renderer2D();

                void draw();

                /**
                 * @brief Writes information about the renderer on the default stdout.
                 */
                void information();
            };
        }
    }
}