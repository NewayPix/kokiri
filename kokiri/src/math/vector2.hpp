#pragma once

#include "core/debug/log.hpp"

#include <cmath>
#include <cstdint>

namespace Kokiri {
    namespace Math {
        template <class T>
        class Vector2 {
        public:
            T x;
            T y;
        public:
            Vector2() : x(0), y(0) {}
            Vector2(T x, T y) {
                x = x;
                y = y;
            }

            ~Vector2() {}

            T operator[](uint8_t i) const {
                T r = 0;

                if (i < 0 || i > 1) {
                    Log::error("v3<T> invalid index i=", i, " returning default 0");
                }

                switch (i) {
                case 0:
                    r = x;
                    break;
                case 1:
                    r = y;
                    break;
                }

                return r;
            }

            T mag() {
                return sqrt(pow(x, 2) + pow(y, 2));
            }

            void norm() {
                auto magnitude = mag();

                x /= magnitude;
                y /= magnitude;
            }

            void scale(T n) {
                x *= n;
                y *= n;
            }
        };
    }
}