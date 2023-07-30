#pragma once

#include <cstdint>
#include <functional>

#include "core/window.hpp"
#include "core/event.hpp"
#include "core/types.hpp"
#include "core/references.hpp"
#include "core/resources.hpp"
#include "core/scene.hpp"
#include "core/sound/sound.hpp"

#include "graphics/opengl/renderer2d.hpp"
#include "graphics/sdl/renderer2d.hpp"

namespace Kokiri {
    class Game {
    private:
        struct GameProperties {
            bool is_running;
            bool is_fullscreen;
            bool is_debug;

            uint16_t fps;
            uint16_t target_fps;

            double target_frame_time; // the frame time objective

            int width;
            int height;
        };

        // local game properties
        GameProperties m_properties;

        // game resources
        ScopedRef<Sound> m_sound;
        SharedRef<Event> m_event;
        SharedRef<Window> m_window;
        ScopedRef<Graphics::OpenGL::Renderer2D> m_opengl_renderer;
        ScopedRef<Graphics::SDL::Renderer2D> m_sdl_renderer;

        std::string m_active_scene;
        std::map<std::string, Scene*> m_scenes;

        ScopedRef<Resources> m_resources;
    private:
        void render();
        void update(f64 dt);
        void event();
    public:
        Game(const std::string& title, int width, int height);
        ~Game();

        /**
         * @brief Binds a function type to a user provided function that gets
         * executed every time the game loops.
         *
         * @param type
         * @param function
         */
        void bind(FunctionType type, Function<void> function);

        void loop();

        // this is to tie a knot when creating textures from the user side
        // of view (need to redesign this!)
        SharedRef<Window> get_window();

        SharedRef<Event> get_event();

        /**
         * @brief Add a scene to the game
         *
         * @param scene
         */
        void add_scene(Scene* scene);

        /**
         * @brief Set the active scene object. It's required to set the active
         * scene or the game will pick the first entry alphabetically.
         *
         * @param scene
         */
        void set_active_scene(const std::string& scene);

        struct Resource {
            std::string name;
            std::string filename;

            ComponentType type;

            v2<u32> dimension;

            Resource(const std::string &name, const std::string& filename, ComponentType type) {
                this->name = name;
                this->filename = filename;
                this->type = type;
                this->dimension = v2<u32>();
            }
        };

        /**
         * @brief Load a resource into the game
         *
         * @param resource
         * @return true If the resource has been successfully loaded
         * @return false If something wrong happened when loading the resource
         */
        bool load(const Resource& resource);

        /**
         * @brief Retrieve a resource loaded from the game
         *
         * @param name
         */
        Component<ComponentType>* retrieve(const std::string& name);
    };
}