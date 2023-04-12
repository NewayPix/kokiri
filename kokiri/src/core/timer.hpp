#pragma once

#include <chrono>
#include <cstdint>

namespace Kokiri {
    namespace Core {
        class Timer {
        public:
            using Nanoseconds = std::chrono::nanoseconds;
            using Milliseconds = std::chrono::milliseconds;
            using Seconds = std::chrono::seconds;

            enum class Unit {
                Nanoseconds,
                Milliseconds,
                Seconds,
            };

            Timer() {
                m_start = std::chrono::high_resolution_clock::now();
            }
            ~Timer() {}

            void reset() {
                m_start = std::chrono::high_resolution_clock::now();
            }

            float since(Unit u = Unit::Seconds) {
                auto now = std::chrono::high_resolution_clock::now();
                auto result = 0.0f;

                switch (u) {
                case Unit::Seconds:
                    result = std::chrono::duration_cast<Seconds>(now - m_start).count();
                    break;
                case Unit::Milliseconds:
                    result = std::chrono::duration_cast<Milliseconds>(now - m_start).count() * 10e-3f;
                    break;
                case Unit::Nanoseconds:
                    result = std::chrono::duration_cast<Nanoseconds>(now - m_start).count() * 10e-9f;
                    break;
                }

                return result;
            }

        private:
            std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
        };
    }
}