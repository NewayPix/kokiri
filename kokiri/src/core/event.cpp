#include "kkr.hpp"
#include "event.hpp"

namespace Kokiri {
    Event::Event() {
        m_key_state = (u8*) SDL_GetKeyboardState(nullptr);

        m_mouse_click = false;
        m_mouse_move = false;

        m_key_down = false;

        m_quit = false;
    }

    Event::~Event() {}

    void Event::pool() {
        clear();

        while (SDL_PollEvent(&m_event)) {
            switch(m_event.type) {
            case SDL_MOUSEMOTION:
                m_mouse_move = true;
                m_mouse_motion_event = m_event.motion;
                break;
            case SDL_MOUSEBUTTONDOWN:
                m_mouse_click = true;
                m_mouse_button_event = m_event.button;
                break;
            case SDL_KEYDOWN:
                m_key_down = true;
                break;
            case SDL_QUIT:
                m_quit = true;
            }
        }
    }

    void Event::clear() {
        m_mouse_click = false;
        m_mouse_move = false;

        m_key_down = false;
    }

    bool Event::is_key_press(Key key) {
        return m_key_down && m_key_state[Utils::to_underlying(key)];
    }

    bool Event::is_mouse_click(Mouse::Buttons button) {
        return m_mouse_click && m_mouse_button_event.button == button;
    }

    bool Event::quit() {
        return m_quit;
    }

    v2<i32> Event::get_mouse_position() {
        v2<i32> p(0, 0);

        SDL_GetMouseState(&p.x, &p.y);

        return p;
    }
}