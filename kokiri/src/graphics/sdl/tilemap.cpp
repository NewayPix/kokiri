#include "kkr.hpp"
#include "tilemap.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            Tilemap::Tilemap(const std::string& file, Tileset* tile_set) : Component::Component(ComponentType::Tilemap) {

            }
            Tilemap::~Tilemap() {}

            void Tilemap::render() {

            }

            void Tilemap::render_layer() {

            }


            u32 Tilemap::at(v3<u32> position) {

            }


            u32 Tilemap::get_width() {}
            u32 Tilemap::get_height() {}
            u32 Tilemap::get_depth() {}
        }
    }
}