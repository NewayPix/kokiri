#pragma once

#include "core/types.hpp"
#include "core/references.hpp"

namespace Kokiri {
    enum class ComponentType {
            Sprite,
            Soundtrack,
            Tilemap,
            Camera,
    };

    template <typename T>
    class Component {
    protected:
        ComponentType m_type;

    public:
        Component(const ComponentType type) {
            m_type = type;
        }

        Component(T t, const ComponentType type) {
            m_type = type;
        };

        virtual ~Component() {};

        ComponentType get_type() const {
            return m_type;
        }

        virtual void render() {};
        virtual void update(f64 dt) {};
    };
}