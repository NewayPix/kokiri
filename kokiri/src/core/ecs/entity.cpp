#include "entity.hpp"

namespace Kokiri {
    Entity::Entity(const std::string& name) {
        m_name = name;

        // TODO: generate UUID
    }

    Entity::~Entity() {}

    const std::string Entity::get_name() {
        return m_name;
    }
}