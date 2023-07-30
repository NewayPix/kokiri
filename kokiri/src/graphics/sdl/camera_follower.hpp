#pragma once

#include "core/ecs/component.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class CameraFollower : public Component {
            public:
                CameraFollower();
                ~CameraFollower();
            };
        }
    }

}