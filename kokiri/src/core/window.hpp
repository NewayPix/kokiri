#pragma once

#include <string>
#include <cinttypes>

#include <SDL2/SDL.h>

#include "core/references.hpp"

namespace Kokiri {
    namespace Core {
        /**
         * @brief An abstraction over the SDL_Window struct that provides an object
         * oriented facilities.
         */
        class Window {
        private:
            SDL_Window* m_window;
            SDL_Renderer* m_window_renderer;

            int m_width;
            int m_height;

        public:
            Window(int width, int height, const std::string &title);
            Window(int width, int height, const std::string &title, int32_t flags);
            ~Window();

            /**
             * @brief Returns a pointer to the current SDL_Window.
             */
            SDL_Window* get_window();
            /**
             * @brief Returns a pointer to the current renderer of the window.
             */
            SDL_Renderer* get_renderer();

            /**
             * @brief Returns the width of the window
             */
            int width();
            /**
             * @brief Returns the height of the window
             */
            int height();
        };
    }
}