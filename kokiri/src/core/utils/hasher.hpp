#pragma once

#include <string>
#include <random>
#include <sstream>
#include <functional>

namespace Kokiri {
    namespace Utils {
        static const bool ___d[] = {0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0};

        static std::random_device              ___rd;
        static std::mt19937_64                 ___gen(___rd());
        static std::uniform_int_distribution<> ___dist(0, 15);

        class Hasher {
        private:
            Hasher() {};
            ~Hasher() {};

        public:
            static std::string uuid() {
                std::stringstream ss;
                ss << std::hex;

                for (int i = 0; i < 16; i++) {
                    if (___d[i]) {
                        ss << "-";
                    }

                    ss << ___dist(___gen);
                    ss << ___dist(___gen);
                }


                return ss.str();
            }

            static std::string hash(const std::string& s) {
                std::stringstream ss;
                ss << std::hex;

                ss << std::hash<std::string>{}(s);

                return ss.str();
            }
        };
    }
}