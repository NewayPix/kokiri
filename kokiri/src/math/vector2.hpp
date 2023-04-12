#pragma once

namespace Kokiri {
    namespace Math {
        template <class T>
        class Vector2 {
        public:
            T m_x;
            T m_y;
        public:
            Vector2(T x, T y) {
                m_x = x;
                m_y = y;
            }

            ~Vector2() {}

            Vector2<T> norm() {
                Vector2<T> normalized = *this;

                normalized.m_x /= mag();
                normalized.m_y /= mag();

                return normalized;
            }

            T mag() {
                return  sqrt(pow(m_x, 2) + pow(m_y, 2));
            }
        };
    }
}