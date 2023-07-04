#pragma once

#include <string>

namespace Kokiri {
    namespace Utils {
        class Strings {
        private:
            Strings() {};
            ~Strings() {};

        public:
            static std::string extension(const std::string &s) {
                std::string e = "";

                auto it = s.find(".");

                for (auto i = it; i < s.size(); i++) {
                    e += s.at(i);
                }

                return e;
            }
        };
    }
}