#pragma once

#include "core/window.hpp"
#include "core/references.hpp"

#include <vector>

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Renderer2D {
            private:
                // stores a reference to an SDL_Renderer
                SharedRef<Window> m_window;
            public:
                Renderer2D(const SharedRef<Window>& window);
                ~Renderer2D();
            };
        }
    }
}