#pragma once

#include <iostream>

namespace Kokiri {
    namespace Core {
        /**
         * @brief
         *
         * @tparam E The enum class
         * @param e The enum class instance
         * @return constexpr std::underlying_type<E>::type The underlying type
         * of the object.
         */
        template <typename E>
        constexpr typename std::underlying_type<E>::type to_underlying(E e) noexcept {
            return static_cast<typename std::underlying_type<E>::type>(e);
        }
    }
}