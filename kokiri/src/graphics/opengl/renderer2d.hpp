#pragma once

#if defined(__WIN32__) || defined(__WIN32) || defined(__MINGW32__)
#include <GL/glext.h>
#endif


#include "context.hpp"

#include "../window.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace OpenGL {
            class Renderer2D {
            public:
                Renderer2D(Window &&window);
                Renderer2D(Window &&window, Context::ContextVersion version);
                ~Renderer2D();

                void draw();

                /**
                 * @brief Writes information about the renderer on the default stdout.
                 */
                void information();
            private:
                // An instance of the OpenGLContext which holds all information of the
                // SDL context. One thing that should be noted is that this is not
                // verified to be a good encapsulation at this moment.
                Context *m_context;
            };
        }
    }
}