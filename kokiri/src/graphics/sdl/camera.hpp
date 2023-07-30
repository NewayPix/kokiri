#pragma once

#include "core/types.hpp"
#include "core/references.hpp"

#include "core/ecs/component.hpp"
#include "core/ecs/entity.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Camera {
                v2<i32> m_position;
                v2<i32> m_speed;

                SharedRef<Entity> m_entity;
            public:
                Camera(v2<i32> position, v2<i32> speed, SharedRef<Entity> entity);
                ~Camera();

                void update(f32 dt);

                v2<i32> get_coordinates();
            };
        }
    }
}