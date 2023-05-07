#pragma once

#include <SDL2/SDL.h>

#include "references.hpp"
#include "types.hpp"

namespace Kokiri {
    class Event {
        static SDL_Event m_event;
        static SDL_MouseMotionEvent m_mouse_motion_event;
        static SDL_MouseButtonEvent m_mouse_button_event;

        static u8 *m_key_state;
    public:
        Event();
        ~Event();

        enum class Mouse {
            LeftButton,
            MiddleButton,
            RightButton,
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
        static void pool();

        static bool is_key_down(Key key);
        static bool is_mouse_click(Mouse mouse);

        static v2<int> get_mouse_position();
    };
}