#include "kkr.hpp"
#include "resources.hpp"

#include "core/debug/log.hpp"

namespace Kokiri {
    Resources::Resources() {
        m_resources = std::unordered_map<std::string, Component<ComponentType>*>();
    }

    Resources::~Resources() {}

    bool Resources::add(const std::string& name, Component<ComponentType>* component) {
        auto ok = m_resources.insert({name, component}).second;

        return ok;
    }

    bool Resources::remove(const std::string& name) {
        for (auto it = m_resources.begin(); it != m_resources.end(); ++it) {
            if (it->first == name) {
                m_resources.erase(it);
                break;
            }
        }
    }

    Component<ComponentType>* Resources::get(const std::string& name) {
        for (auto it = m_resources.begin(); it != m_resources.end(); ++it) {
            if (it->first == name) {
                return it->second;
            }
        }
    }

    bool Resources::free() {
        for (auto it = m_resources.begin(); it != m_resources.end(); ++it) {
            ::free(it->second);

            m_resources.erase(it);
        }

        return true;
    }
}
