#pragma once

#include <memory>

namespace Kokiri {
    namespace Core {
        template <typename T>
        using Reference = std::shared_ptr<T>;

        template <typename T, typename ...Args>
        constexpr Reference<T> make_reference(Args&& ...args) {
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

