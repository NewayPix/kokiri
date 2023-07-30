#include "kkr.hpp"

#include "core/scene.hpp"

namespace Kokiri {
    Scene::Scene(SharedRef<Window> window, const std::string& name) {
        m_window = window;
        m_scene_name = name;

        m_entities = std::unordered_map<std::string, Entity*>();
    }

    Scene::~Scene() {

    }

    void Scene::bind(FunctionType type, Function<void> function) {
        m_functions.emplace(type, function);
    }

    std::string Scene::get_name() {
        return m_scene_name;
    }

    void Scene::add_entity(Entity* e) {
        auto n = e->get_name();
        auto p = m_entities.emplace(std::make_pair(n, e));

        if (!p.second) {
            Log::error("failed to insert entity ", n);
        }
    }

    void Scene::remove_entity(Entity* e) {
        for (auto it = m_entities.begin(); it != m_entities.end(); ++it) {
            if (it->second == e) {
                m_entities.erase(it);
                break;
            }
        }
    }

    void Scene::update(f64 dt) {
        for (auto e : m_entities) {
            e.second->update(dt);
        }
    }

    void Scene::render() {
        for (auto e : m_entities) {
            e.second->render();
        }
    }

    void Scene::event() {
        try {
            m_functions.at(FunctionType::Event)();
        } catch (std::exception e) {
            Log::error("failed to get event function on scene ", m_scene_name, " ", e.what());
        }

        for (auto e : m_entities) {
            // e.second.event();
        }
    }
}