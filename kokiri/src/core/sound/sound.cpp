#include "kkr.hpp"
#include "sound.hpp"

#include <SDL2/SDL_mixer.h>

namespace Kokiri {
    Sound::Sound() {
        int r = Mix_Init(MIX_INIT_OGG);

        if (r == 0) {
            Log::error("failed to initialize audio");
        }
    }

    Sound::~Sound() {
        Log::info("destroying SDL mixer");
        Mix_Quit();
    }
}