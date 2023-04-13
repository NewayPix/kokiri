#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "core/references.hpp"
#include "core/window.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Sprite {
            private:
                SDL_Texture* m_texture;
                SDL_Rect m_rect;

                std::string m_filename;

                Core::SharedRef<Core::Window> m_window;
            public:
                Sprite(Core::SharedRef<Core::Window> window, const std::string& filename);
                ~Sprite();

                void render(int x, int y);
            };
        }
    }
}
