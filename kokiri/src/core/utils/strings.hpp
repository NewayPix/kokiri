#pragma once

#include <string>
#include <vector>
#include <sstream>

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

            static std::vector<std::string> split(const std::string& s, const char& delimiter) {
                std::stringstream ss(s);

                std::string item;
                std::vector<std::string> items;

                while (std::getline(ss, item, delimiter)) {
                    items.push_back(item);
                }

                return items;
            }
        };
    }
}