#pragma once

#include <SDL2/SDL.h>

namespace Kokiri {
    namespace Core {
        class Event {
        private:
            SDL_Event event;

        public:
            Event() {};
            ~Event() {};

            SDL_Event *get() {
                return &event;
            }
        };
    }
}