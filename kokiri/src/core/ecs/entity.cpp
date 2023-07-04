#include "kkr.hpp"
#include "entity.hpp"

#include "core/utils/hasher.hpp"

namespace Kokiri {
    Entity::Entity(const std::string &name) {
        m_name = name;
        m_uuid = Utils::Hasher::uuid();
    }

    Entity::~Entity() {}

    const std::string Entity::get_name() {
        return m_name;
    }

    void Entity::add_component(Component<ComponentType>* c) {
        m_components.push_back(c);
    }

    void Entity::remove_component(Component<ComponentType>* c) {
        auto it = std::remove(m_components.begin(), m_components.end(), c);

        m_components.erase(it, m_components.end());
    }

    void Entity::update(f32 dt) {}
    void Entity::render() {}
}