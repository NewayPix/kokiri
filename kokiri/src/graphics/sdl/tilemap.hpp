#pragma once

#include "core/types.hpp"
#include "core/ecs/component.hpp"

#include "graphics/sdl/tileset.hpp"

#include <string>

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Tilemap : public Component<ComponentType> {
            private:

            public:
                Tilemap(const std::string& file, Tileset* tile_set);
                ~Tilemap();

                u32 at(v3<u32> position);

                void render() override;
                void render_layer();

                u32 get_width();
                u32 get_height();
                u32 get_depth();
            };
        }
    }
}
