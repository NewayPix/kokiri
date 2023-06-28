#pragma once

#include "core/references.hpp"

namespace Kokiri {
    enum class ComponentType {
            Sprite,
            Soundtrack,
    };

    template <typename T>
    class Component {
    private:
        ComponentType m_type;

    public:
        Component(const ComponentType type) {
            m_type = type;
        }
        
        Component(T t, const ComponentType type) {
            m_type = type;
        };

        ~Component() {};

        ComponentType get_type() const {
            return m_type;
        }
    };
}