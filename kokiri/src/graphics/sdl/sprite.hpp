#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "core/window.hpp"
#include "core/types.hpp"
#include "core/references.hpp"

#include "core/ecs/component.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Sprite : public Component<ComponentType> {
            private:
                SDL_Surface* m_surface;
                SDL_Texture* m_texture;
                SDL_Rect m_rect;

                std::string m_filename;

                SharedRef<Window> m_window;
            public:
                Sprite(SharedRef<Window> window, const std::string& filename);
                ~Sprite();

                void render(i32 x, i32 y);

                u32 get_width();
                u32 get_height();
            };
        }
    }
}
