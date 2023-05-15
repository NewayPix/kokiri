#pragma once

#include <SDL2/SDL.h>

#include "references.hpp"
#include "types.hpp"

namespace Kokiri {
    class Event {
    private:
        SDL_Event m_event;
        SDL_MouseMotionEvent m_mouse_motion_event;
        SDL_MouseButtonEvent m_mouse_button_event;

        u8 *m_key_state;

        bool m_mouse_click;
        bool m_mouse_move;

        bool m_key_pressed;
    public:
        Event();
        ~Event();

        class Mouse {
        public:
            enum Buttons {
                LeftButton = 1,
                MiddleButton = 2,
                RightButton = 3,
            };
        };

        enum class Key {
            // numbers
            _0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
            // letters
            A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U,
            V, X, Y, Z,
            // special F keys
            F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        };

        /**
         * @brief Pool events from SDL
         *
         */
        void pool();

        /**
         * @brief Clear any registered event
         *
         */
        void clear();

        bool is_key_down(Key key);
        bool is_mouse_click(Mouse::Buttons mouse);

        /**
         * @brief Get the mouse position
         *
         * @return v2<int> A two dimensional vector containing the x and y
         * coordinates of the mouse on the window
         */
        v2<int> get_mouse_position();
    };
}