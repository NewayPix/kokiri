#pragma once

#include "core/ecs/component.hpp"

#include "graphics/sdl/sprite.hpp"

namespace Kokiri {
    class Entity {
    private:
        std::string m_name;
        std::string m_uuid;

        // Graphics::SDL::Sprite m_sprite;
    public:
        Entity(const std::string& name);
        ~Entity();

        const std::string get_name();
    };
}