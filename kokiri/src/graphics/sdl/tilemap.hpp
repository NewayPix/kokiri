#pragma once

#include "core/types.hpp"
#include "core/ecs/component.hpp"

#include "graphics/sdl/tileset.hpp"

#include <string>
#include <vector>

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Tilemap : public Component<ComponentType> {
            private:
                SharedRef<Window> m_window;

                std::string m_file;

                Tileset* m_tileset;

                // a collection of tiles given its position on the layer (z-axis)
                std::vector<std::vector<i32>> m_tiles;

                i32 m_rows;
                i32 m_columns; // x * columns + y = index
                i32 m_layers;
            public:
                Tilemap(SharedRef<Window> window, const std::string& file, Tileset* tileset);
                ~Tilemap();

                i32 at(v3<i32> position);

                void render() override;
                void render_layer(i32 layer, v2<i32> position);

                u32 get_width();
                u32 get_height();
                i32 get_depth();
            };
        }
    }
}
