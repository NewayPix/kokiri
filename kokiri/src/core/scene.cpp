#include "kkr.hpp"

#include "core/scene.hpp"

namespace Kokiri {
    Scene::Scene(SharedRef<Window> window, const std::string& name) {
        m_window = window;
        m_scene_name = name;

        m_entities = std::unordered_map<std::string, Entity>();
    }

    Scene::~Scene() {

    }

    void Scene::add_entity(const Entity& e) {
        //auto n = e.get_name();
        //auto p = m_entities.emplace(std::make_pair(n, e));

        //if (!p.second) {
        //    Log::error("failed to insert entity ", n);
        //}
    }

    void Scene::update(f32 dt) {
        for (auto e : m_entities) {
            e.second.update(dt);
        }
    }

    void Scene::render() {
        for (auto e : m_entities) {
            e.second.render();
        }
    }

    void Scene::event() {
        for (auto e : m_entities) {
            // e.second.event();
        }
    }
}