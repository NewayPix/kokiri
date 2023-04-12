#pragma once

#include <memory>

namespace Kokiri {
    namespace Core {
        template <typename T>
        using SharedRef = std::shared_ptr<T>;

        template <typename T, typename ...Args>
        constexpr SharedRef<T> make_shared_ref(Args&& ...args) {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }

        template <typename T>
        using ScopedRef = std::unique_ptr<T>;

        template <typename T, typename ...Args>
        constexpr ScopedRef<T> make_scope_ref(Args&& ...args) {
            return std::make_unique<T>(std::forward<Args>(args)...);
        }
    }
}

