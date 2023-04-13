#pragma once

#include <functional>

namespace Kokiri {
    namespace Core {
        enum class FunctionType {
            Render,
            Update,
        };

        template <typename Type, typename ...Args>
        using Function = std::function<Type(Args...)>;
    }
}