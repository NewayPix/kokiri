#pragma once

#include <string>

#include <SDL2/SDL_mixer.h>

namespace Kokiri {
    class Track{
    private:
        Mix_Music* m_track;
    public:
        Track(const std::string& filename);
        ~Track();

        void play(int times = -1);
        void stop();
    };
}