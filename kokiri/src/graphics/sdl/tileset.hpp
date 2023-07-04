#pragma once

#include <string>

#include "core/types.hpp"
#include "core/references.hpp"

#include "graphics/sdl/sprite.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Tileset {
            private:
                ScopedRef<Sprite> m_sprite;
                SharedRef<Window> m_window;

                std::string m_filename;

                u32 m_tile_width;
                u32 m_tile_height;

                u32 m_rows;
                u32 m_columns;
            public:
                /**
                 * @brief Construct a new Tileset object
                 *
                 * @param window
                 * @param tileset
                 * @param dimension The dimension of the tile, always in the order
                 * width and then heigth.
                 */
                Tileset(SharedRef<Window> window, const std::string& tileset, v2<u32> dimension);
                ~Tileset();

                void render(u32 index);

                u32 get_width();
                u32 get_height();
            };
        }
    }
}