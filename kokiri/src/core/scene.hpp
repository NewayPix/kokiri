#pragma once

#include "core/window.hpp"
#include "core/functions.hpp"
#include "core/ecs/entity.hpp"

#include <unordered_map>

namespace Kokiri {
    class Scene {
    private:
        SharedRef<Window> m_window;

        std::string m_scene_name;

        std::unordered_map<std::string, Entity*> m_entities;

        // stored functions that a user would then provide through bind.
        std::map<FunctionType, Function<void>> m_functions;
    public:
        Scene(SharedRef<Window> window, const std::string& name);
        ~Scene();

        /**
         * @brief Binds a function type to a user provided function that gets
         * executed every time the game loops.
         *
         * @param type
         * @param function
         */
        void bind(FunctionType type, Function<void> function);

        std::string get_name();

        /**
         * @brief Get the entity object, should be transformed into whatever
         * object you want.
         *
         * @return Entity
         */
        Entity get_entity();

        void add_entity(Entity* e);
        void remove_entity(Entity* e);

        void render();
        void event();
        void update(f32 dt);
    };
}