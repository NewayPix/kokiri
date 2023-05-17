#pragma once

#include <cstdint>

#include "math/vector2.hpp"
#include "math/vector3.hpp"

namespace Kokiri {
    template <typename T>
    using v2 = Math::Vector2<T>;

    template <typename T>
    using v3 = Math::Vector3<T>;

    using u8  = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;

    using i8  = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
}