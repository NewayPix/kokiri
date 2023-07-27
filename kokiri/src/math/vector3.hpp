#pragma once

#include "core/debug/log.hpp"

#include <cmath>
#include <cstdint>

namespace Kokiri {
    namespace Math {
        template <class T>
        class Vector3 {
        public:
            T x;
            T y;
            T z;
        public:
            Vector3() : x(0), y(0), z(0) {}
            Vector3(T x, T y, T z) {
                x = x;
                y = y;
                z = z;
            }

            ~Vector3() {}

            T operator[](uint8_t i) const {
                T r = 0;

                if (i < 0 || i > 2) {
                    Log::error("v3<T> invalid index i=", i, " returning default 0");
                }

                switch (i) {
                case 0:
                    r = x;
                    break;
                case 1:
                    r = y;
                    break;
                case 2:
                    r = z;
                    break;
                }

                return r;
            }

            T mag() {
                return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
            }

            void norm() {
                auto magnitude = mag();

                x /= magnitude;
                y /= magnitude;
                z /= magnitude;
            }

            void scale(T n) {
                x *= n;
                y *= n;
                z *= n;
            }
        };
    }
}