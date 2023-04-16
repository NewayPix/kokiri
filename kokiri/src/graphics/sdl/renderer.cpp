#include "kkr.hpp"
#include "renderer.hpp"

#include <SDL2/SDL_image.h>

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            Renderer::Renderer() {
                int r = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

                if (r == 0) {
                    Log::error("failed to initialize image subsystem");
                }
            }

            Renderer::~Renderer() {
                Log::info("destroying image renderer");
                IMG_Quit();
            }
        }
    }
}