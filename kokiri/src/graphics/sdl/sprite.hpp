#pragma once

#include <string>

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            class Sprite {
            public:
                Sprite(const std::string& filename);
                ~Sprite();
            };
        }
    }
}
