#pragma once

#include "core/ecs/entity.hpp"

#include <map>

namespace Kokiri {
    class Scene {
    private:
        std::map<std::string, Entity> m_entities;
    public:
        Scene();
        ~Scene();

        void add_entity(const Entity& e);
        void remove_entity(const Entity& e);
    };
}