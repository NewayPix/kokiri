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

        bool m_key_down;

        bool m_quit;
    public:
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
            _0 = SDL_SCANCODE_0,
            _1 = SDL_SCANCODE_1,
            _2 = SDL_SCANCODE_2,
            _3 = SDL_SCANCODE_3,
            _4 = SDL_SCANCODE_4,
            _5 = SDL_SCANCODE_5,
            _6 = SDL_SCANCODE_6,
            _7 = SDL_SCANCODE_7,
            _8 = SDL_SCANCODE_8,
            _9 = SDL_SCANCODE_9,
            // letters
            A = SDL_SCANCODE_A,
            B = SDL_SCANCODE_B,
            C = SDL_SCANCODE_C,
            D = SDL_SCANCODE_D,
            E = SDL_SCANCODE_E,
            F = SDL_SCANCODE_F,
            G = SDL_SCANCODE_G,
            H = SDL_SCANCODE_H,
            I = SDL_SCANCODE_I,
            J = SDL_SCANCODE_J,
            K = SDL_SCANCODE_K,
            L = SDL_SCANCODE_L,
            M = SDL_SCANCODE_M,
            N = SDL_SCANCODE_N,
            O = SDL_SCANCODE_O,
            P = SDL_SCANCODE_P,
            Q = SDL_SCANCODE_Q,
            R = SDL_SCANCODE_R,
            S = SDL_SCANCODE_S,
            T = SDL_SCANCODE_T,
            U = SDL_SCANCODE_U,
            V = SDL_SCANCODE_V,
            X = SDL_SCANCODE_X,
            Y = SDL_SCANCODE_Y,
            Z = SDL_SCANCODE_Z,
            // special F keys
            F1 = SDL_SCANCODE_F1,
            F2 = SDL_SCANCODE_F2,
            F3 = SDL_SCANCODE_F3,
            F4 = SDL_SCANCODE_F4,
            F5 = SDL_SCANCODE_F5,
            F6 = SDL_SCANCODE_F6,
            F7 = SDL_SCANCODE_F7,
            F8 = SDL_SCANCODE_F8,
            F9 = SDL_SCANCODE_F9,
            F10 = SDL_SCANCODE_F10,
            F11 = SDL_SCANCODE_F11,
            F12 = SDL_SCANCODE_F12,

            ESC = SDL_SCANCODE_ESCAPE,

            UP = SDL_SCANCODE_UP,
            DOWN = SDL_SCANCODE_DOWN,
            LEFT = SDL_SCANCODE_LEFT,
            RIGHT = SDL_SCANCODE_RIGHT
        };

        Event();
        ~Event();

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

        bool is_key_press(Key key);

        bool is_mouse_click(Mouse::Buttons mouse);

        bool quit();

        /**
         * @brief Get the mouse position
         *
         * @return v2<int> A two dimensional vector containing the x and y
         * coordinates of the mouse on the window
         */
        v2<int> get_mouse_position();
    };
}