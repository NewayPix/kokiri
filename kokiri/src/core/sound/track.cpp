#include "kkr.hpp"
#include "track.hpp"

#include <SDL2/SDL_mixer.h>

namespace Kokiri {
    namespace Core {
        Track::Track(const std::string& filename) {
            int r = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

            if (r != 0) {
                Log::error("failed to open audio device");
            }

            m_track = Mix_LoadMUS(filename.c_str());

            if (m_track == nullptr) {
                Log::error("failed to open audio track ", filename);
            }
        }

        Track::~Track() {
            Log::info("closing audio track");
            Mix_CloseAudio();
        }

        void Track::play() {
            if (m_track == nullptr) {
                return;
            }

            Mix_PlayMusic(m_track, -1);
        }

        void Track::stop() {
            Mix_FadeOutMusic(350);
        }
    }
}