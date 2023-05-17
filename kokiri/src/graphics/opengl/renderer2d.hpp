#pragma once

#if defined(__WIN32__) || defined(__WIN32) || defined(__MINGW32__)
#include <GL/glext.h>
#endif

#include <map>

#include <SDL2/SDL.h>

#include "core/window.hpp"
#include "core/references.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            class Renderer2D {
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

                Renderer2D(const SharedRef<Window>& window);
                ~Renderer2D();

                void draw();

                /**
                 * @brief Swap the GL context buffers from a window.
                 *
                 * @param window
                 */
                void swap_buffers(SharedRef<Window>& window);

                /**
                 * @brief Writes information about the renderer on the default stdout.
                 */
                void information();

            private:
                // An instance of the OpenGLContext which holds all information of the
                // SDL context. One thing that should be noted is that this is not
                // verified to be a good encapsulation at this moment.
                SharedRef<SDL_GLContext> m_context;

                const std::map<Version, std::pair<int, int>> m_version = {
                    {Version::OPENGL_3_1, std::make_pair(3, 1)},
                    {Version::OPENGL_3_2, std::make_pair(3, 2)},
                    {Version::OPENGL_4_0, std::make_pair(4, 0)},
                    {Version::OPENGL_4_5, std::make_pair(4, 5)},
                    {Version::OPENGL_4_6, std::make_pair(4, 6)},
                };
            };
        }
    }
}