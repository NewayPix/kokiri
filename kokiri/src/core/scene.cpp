#include "kkr.hpp"
#include "scene.hpp"

namespace Kokiri {
    Scene::Scene() {
        m_entities = std::map<std::string, Entity>();
    }

    Scene::~Scene() {

    }

    void add_entity(const Entity& e) {
        m_entities[e.get_name()] = e;
    }
}