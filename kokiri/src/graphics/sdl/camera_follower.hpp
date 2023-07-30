#pragma once

#include "core/ecs/component.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class CameraFollower : public Component<ComponentType> {
            public:
                CameraFollower();
                ~CameraFollower();

                void render() override;
                void update(f64 dt) override;
            };
        }
    }
}