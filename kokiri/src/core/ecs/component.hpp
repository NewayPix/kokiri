#pragma once

#include "core/references.hpp"

namespace Kokiri {
    template <typename T>
    class Component {
    private:
        SharedRef<T> m_component;
    public:
        Component(T t) {};
        ~Component() {};
    };
}