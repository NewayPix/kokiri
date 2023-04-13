#include "kkr.hpp"
#include "sound.hpp"

#include <SDL2/SDL_mixer.h>

namespace Kokiri {
    namespace Core {
        Sound::Sound() {
            int r = Mix_Init(MIX_INIT_OGG);

            if (r == 0) {
                Log::error("failed to initialize audio");
            }
        }

        Sound::~Sound() {
            Log::info("destroying mixer");
            Mix_Quit();
        }
    }
}