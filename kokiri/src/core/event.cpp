#include "kkr.hpp"
#include "event.hpp"


namespace Kokiri {

    Event::Event() {}
    Event::~Event() {}

    void Event::pool() {
        while (SDL_PollEvent(&m_event)) {
            switch(m_event.type) {
            case SDL_MOUSEMOTION:

                break;
            case SDL_KEYDOWN:
                break;
            }
        }
    }

    bool Event::is_key_down(Key key) {
        return false;
    }

    bool Event::is_mouse_click(Mouse mouse) {
        return false;
    }

    v2<int> Event::get_mouse_position() {
        v2<int> p;

        SDL_GetMouseState(&p.x, &p.y);

        return p;
    }
}