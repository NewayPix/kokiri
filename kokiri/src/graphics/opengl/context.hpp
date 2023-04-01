#pragma once

#include <SDL2/SDL.h>

#include "../window.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            /**
             * @brief Represents an OpenGL context within the engine. It holds an instance
             * to SDL_GLContext and has a lot of utilities to choose the right version to
             * init the context.
             */
            class Context {
            private:
                // A handler to the OpenGL context
                SDL_GLContext m_context;

            public:
                /// Current available types of context that cold be created.
                enum class ContextType {
                    CORE,
                    COMPABILITY
                };

                /// Describe the current version of OpenGL versions that could be used to
                /// create the context.
                enum class ContextVersion {
                    OPENGL_3_1,
                    OPENGL_3_2,
                    OPENGL_4_0,
                    OPENGL_4_5,
                    OPENGL_4_6,
                };

                /**
                 * @brief Constructs a context according to the specified version of profile
                 * and version.
                 *
                 * @param window A universal reference to a window
                 * @param context
                 * @param version
                 */
                Context(Window &&window, ContextType context, ContextVersion version = ContextVersion::OPENGL_3_1);
                ~Context();

                /**
                * @brief Returns a pointer to an OpenGL context which of type SDL_GLContext
                */
                SDL_GLContext *get_context();
            };
        }
    }
}