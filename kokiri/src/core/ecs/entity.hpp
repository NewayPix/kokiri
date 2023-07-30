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

        SDL_Rect m_rect;
    public:
        struct EntityProperties {
            v2<u32> size;
            v2<i32> position;

            std::string name;

            EntityProperties(const std::string& name) {
                this->name = name;

                size = v2<u32>();
                position = v2<i32>();
            }

            EntityProperties(const std::string& name, v2<u32>& size, v2<i32>& position) {
                this->name = name;
                this->size = size;
                this->position = position;
            }
        };

        Entity(EntityProperties& properties);
        virtual ~Entity();

        const std::string get_name();

        void set_position(v2<i32> p);
        void set_position(i32 x, i32 y);

        void update(f64 dt);
        void render();
        void event();

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