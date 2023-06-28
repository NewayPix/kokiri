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

        void add_component(const Component<ComponentType>& c);
        void remove_component(const Component<ComponentType>& c);
    };
}