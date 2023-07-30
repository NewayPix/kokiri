#include "kkr.hpp"
#include "camera.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            Camera::Camera(v2<i32> position, v2<i32> speed, SharedRef<Entity> entity) {
                m_position = position;
                m_speed = speed;
                m_entity = entity;
            }

            Camera::~Camera() {}

            void Camera::update(f64 dt) {}

            v2<i32> Camera::get_coordinates() {
                return m_position;
            }
        }
    }
}