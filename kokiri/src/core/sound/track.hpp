#pragma once

#include "core/ecs/component.hpp"

#include <string>

#include <SDL2/SDL_mixer.h>

namespace Kokiri {
    class Track : public Component<ComponentType> {
    private:
        Mix_Music* m_track;
    public:
        Track(const std::string& filename);
        ~Track();

        void play(int times = -1);
        void stop();
    };
}