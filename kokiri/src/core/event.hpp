#pragma once

#include <SDL2/SDL.h>

namespace Kokiri {
    namespace Core {
        class Event {

        public:
            Event() {};
            ~Event() {};

            SDL_Event event;
        };
    }
}