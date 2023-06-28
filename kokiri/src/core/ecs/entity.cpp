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
}