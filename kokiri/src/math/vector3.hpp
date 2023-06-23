#pragma once

#include <cmath>

namespace Kokiri {
    namespace Math {
        template <class T>
        class Vector3 {
        public:
            T x;
            T y;
            T z;
        public:
            Vector3(T x, T y, T z) {
                x = x;
                y = y;
                z = z;
            }

            ~Vector3() {}

            Vector3<T> norm() {
                Vector3<T> normalized = *this;

                normalized.x /= mag();
                normalized.y /= mag();
                normalized.z /= mag();

                return normalized;
            }

            T mag() {
                return  sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
            }

            void scale(T n) {
                this->x *= n;
                this->y *= n;
                this->z *= n;
            }
        };
    }
}