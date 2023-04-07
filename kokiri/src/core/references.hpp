#pragma once

#include <memory>

namespace Kokiri {
    namespace Core {
        template <typename T>
        using Shared = std::shared_ptr<T>;

        template <typename T, typename ...Args>
        constexpr Shared<T> make_shared(Args&& ...args) {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }

        template <typename T>
        using Scope = std::unique_ptr<T>;

        template <typename T, typename ...Args>
        constexpr Scope<T> make_scope(Args&& ...args) {
            return std::make_unique<T>(std::forward<Args>(args)...);
        }
    }
}

