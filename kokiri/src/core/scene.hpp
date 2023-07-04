#pragma once

#include "core/window.hpp"
#include "core/ecs/entity.hpp"

#include <unordered_map>

namespace Kokiri {
    class Scene {
    private:
        SharedRef<Window> m_window;

        std::string m_scene_name;

        std::unordered_map<std::string, Entity> m_entities;
    public:
        Scene(SharedRef<Window> window, const std::string& name);
        ~Scene();

        /**
         * @brief Get the entity object, should be transformed into whatever
         * object you want.
         *
         * @return Entity
         */
        Entity get_entity();

        void add_entity(const Entity& e);
        void remove_entity(const Entity& e);

        void render();
        void event();
        void update(f32 dt);
    };
}