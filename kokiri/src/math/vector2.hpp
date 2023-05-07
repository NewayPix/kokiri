#pragma once

namespace Kokiri {
    namespace Math {
        template <class T>
        class Vector2 {
        public:
            T x;
            T y;
        public:
            Vector2(T x, T y) {
                x = x;
                y = y;
            }

            ~Vector2() {}

            Vector2<T> norm() {
                Vector2<T> normalized = *this;

                normalized.x /= mag();
                normalized.y /= mag();

                return normalized;
            }

            T mag() {
                return  sqrt(pow(x, 2) + pow(y, 2));
            }
        };
    }
}