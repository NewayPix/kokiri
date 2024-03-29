#include "kkr.hpp"
#include "sprite.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            Sprite::Sprite(SharedRef<Window> window, const std::string& filename) : Component::Component(ComponentType::Sprite) {
                m_window = window;
                m_filename = filename;

                m_texture = IMG_LoadTexture(m_window.get()->get_renderer(), filename.c_str());

                if (m_texture == nullptr) {
                    Log::error(
                        "failed to load image ",
                        filename,
                        ", reason ",
                        IMG_GetError()
                    );

                    exit(1);
                }

                int w = 0;
                int h = 0;

                int r = SDL_QueryTexture(m_texture, nullptr, nullptr, &w, &h);
                if (r != 0) {
                    Log::error("failed to query texture properties, reason ", IMG_GetError());
                    exit(1);
                }

                m_rect.w = w;
                m_rect.h = h;
            }

            Sprite::~Sprite() {
                Log::info("destroying texture ", m_filename);
                SDL_DestroyTexture(m_texture);
            }

            void Sprite::render(i32 x, i32 y) {
                m_rect.x = x;
                m_rect.y = y;

                SDL_RenderCopy(m_window.get()->get_renderer(), m_texture, nullptr, &m_rect);
            }

            u32 Sprite::get_width() {
                return u32(m_rect.w);
            }

            u32 Sprite::get_height() {
                return u32(m_rect.h);
            }
        }
    }
}
