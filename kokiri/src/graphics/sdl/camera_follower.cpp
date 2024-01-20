#include "kkr.hpp"
#include "camera_follower.hpp"

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            CameraFollower::CameraFollower() : Component::Component(ComponentType::Camera) {}
            CameraFollower::~CameraFollower() {}

            void CameraFollower::render() {}
            void CameraFollower::update(f64 dt) {}
        }
    }
}
