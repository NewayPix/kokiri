#include "kkr.hpp"
#include "renderer2d.hpp"

#include <SDL2/SDL_image.h>

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            Renderer2D::Renderer2D(const SharedRef<Window>& window) {
                m_window = window;

                int r = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

                if (r == 0) {
                    Log::error("failed to initialize image subsystem");
                }
            }

            Renderer2D::~Renderer2D() {
                Log::info("destroying SDL renderer");
                IMG_Quit();
            }
        }
    }
}