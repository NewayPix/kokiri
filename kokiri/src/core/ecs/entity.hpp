#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "core/types.hpp"
#include "core/ecs/component.hpp"

namespace Kokiri {
    /**
     * @brief Entity represents a unity of something in the game engine, it is
     * an abstract class. It can have components which are added by the user at
     * will.
     *
     */
    class Entity {
    private:
        std::string m_name;
        std::string m_uuid;

        std::vector<Component<ComponentType>*> m_components;

        SDL_Rect m_dimensions;
    protected:
        Entity(const std::string &name);
    public:
        virtual ~Entity();

        const std::string get_name();

        void update(f32 dt);
        void render();

        void add_component(Component<ComponentType>* c);

        /**
         * @brief Removes the component from the entity. If the component
         * doesn't exist, it doesn't do anything. If the component exists, it is
         * removed from the entity but the memory should be freed manually by
         * the caller (up to this point).
         *
         * @param c
         */
        void remove_component(Component<ComponentType>* c);
    };
}