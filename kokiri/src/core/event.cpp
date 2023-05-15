#include "kkr.hpp"
#include "event.hpp"

namespace Kokiri {
    Event::Event() {
        m_key_state = SDL_GetKeyboardState(nullptr);
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
            case SDL_MOUSEBUTTONUP:
                m_mouse_click = true;
                m_mouse_button_event = m_event.button;
                break;
            case SDL_KEYDOWN:
                m_key_pressed = true;
                break;
            }
        }
    }

    void Event::clear() {
        m_mouse_click = false;
        m_mouse_move = false;

        m_key_pressed = false;
    }

    bool Event::is_key_down(Key key) {
        return false;
    }

    bool Event::is_mouse_click(Mouse::Buttons button) {
        return m_mouse_click && m_mouse_button_event.button == button;
    }

    v2<int> Event::get_mouse_position() {
        v2<int> p;

        SDL_GetMouseState(&p.x, &p.y);

        return p;
    }
}