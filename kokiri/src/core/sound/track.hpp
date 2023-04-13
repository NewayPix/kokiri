#pragma once

#include <string>

#include <SDL2/SDL_mixer.h>

namespace Kokiri {
    namespace Core {
        class Track{
        private:
            Mix_Music* m_track;
        public:
            Track(const std::string& filename);
            ~Track();

            void play();
            void stop();
        };
    }
}