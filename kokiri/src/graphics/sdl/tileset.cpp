#include "kkr.hpp"
#include "tileset.hpp"

#include "core/debug/log.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            Tileset::Tileset(SharedRef<Window> window, const std::string& tileset, v2<u32> dimension) {
                m_window = window;
                m_filename = tileset;

                m_sprite = make_scope_ref<Sprite>(window, tileset);

                m_tile_width = dimension.x;
                m_tile_height = dimension.y;

                // TODO: check calculation below
                m_columns = m_sprite.get()->get_width()/m_tile_width;
                m_rows = m_sprite.get()->get_height()/m_tile_height;
            }

            Tileset::~Tileset() {}

            void Tileset::render(u32 index) {
                //SDL_RenderCopy(m_window->get_renderer(), m_sprite->)
            }

            u32 Tileset::get_width() {
                return m_tile_width;
            }

            u32 Tileset::get_height() {
                return m_tile_height;
            }
        }
    }
}