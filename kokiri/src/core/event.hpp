#pragma once

#include <SDL2/SDL.h>

namespace Kokiri {
    class Event {

    public:
        Event() {};
        ~Event() {};

        SDL_Event event;
    };
}