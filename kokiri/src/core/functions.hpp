#pragma once

#include <functional>

namespace Kokiri {
    enum class FunctionType {
        Render,
        Update,
        Event,
    };

    template <typename Type, typename ...Args>
    using Function = std::function<Type(Args...)>;
}