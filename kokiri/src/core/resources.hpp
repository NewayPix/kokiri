#pragma once

#include "core/ecs/component.hpp"

#include <unordered_map>

namespace Kokiri {
    class Resources {
    private:
        std::unordered_map<std::string, Component<ComponentType>*> m_resources;

        Resources(const Resources& r) = delete;
    public:
        Resources();
        ~Resources();

        bool add(const std::string& name, Component<ComponentType>* c);
        bool remove(const std::string& name);

        void free();

        Component<ComponentType>* get(const std::string& name);
    };
}