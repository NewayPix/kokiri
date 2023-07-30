#include "kkr.hpp"
#include "entity.hpp"

#include "core/utils/hasher.hpp"

#include "core/sound/sound.hpp"
#include "core/sound/track.hpp"

#include "graphics/sdl/sprite.hpp"

namespace Kokiri {
    Entity::Entity(EntityProperties& properties) {
        m_name = properties.name;

        m_rect = SDL_Rect();
        m_rect.x = properties.position.x;
        m_rect.y = properties.position.y;
        m_rect.w = properties.size.x;
        m_rect.h = properties.size.y;

        m_uuid = Utils::Hasher::uuid();
    }

    Entity::~Entity() {}

    const std::string Entity::get_name() {
        return m_name;
    }

    void Entity::set_position(v2<i32> p) {
        this->m_rect.x = p.x;
        this->m_rect.y = p.y;
    }

    void Entity::set_position(i32 x, i32 y) {
        this->m_rect.x = x;
        this->m_rect.y = y;
    }

    void Entity::add_component(Component<ComponentType>* c) {
        m_components.push_back(c);
    }

    void Entity::remove_component(Component<ComponentType>* c) {
        auto it = std::remove(m_components.begin(), m_components.end(), c);

        m_components.erase(it, m_components.end());
    }

    void Entity::update(f64 dt) {}

    void Entity::render() {
        for (auto c : m_components) {
            auto t = c->get_type();

            switch (t) {
                case ComponentType::Sprite:
                {
                    auto s = dynamic_cast<Graphics::SDL::Sprite*>(c);

                    s->render(m_rect.x, m_rect.y);
                }
                case ComponentType::Tilemap:
                {

                }
                break;
                case ComponentType::Soundtrack:
                break;
            }
        }
    }

    void Entity::event() {}

    void Entity::play(std::string music) {
        Track* m = nullptr;

        for (auto c : m_components) {
            auto t = c->get_type();

            switch (t) {
            case ComponentType::Soundtrack:
            {
                m = (Track*) c;
                goto play;
            }
            break;
            }
        }

        play:

        if (m != nullptr) {
            m->play();
        }
    }
}