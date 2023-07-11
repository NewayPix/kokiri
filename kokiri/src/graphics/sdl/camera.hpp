#pragma once

#include "core/types.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Camera {
                v2<i32> position;
            public:
                Camera();
                ~Camera();
            };
        }
    }
}