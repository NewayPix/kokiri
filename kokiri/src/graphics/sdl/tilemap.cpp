#include "kkr.hpp"
#include "tilemap.hpp"

#include "core/utils/strings.hpp"

#include <fstream>
#include <sstream>
#include <utility>

namespace Kokiri {
    namespace Graphics {
        namespace SDL {
            Tilemap::Tilemap(SharedRef<Window> window, const std::string& file, Tileset* tileset) : Component::Component(ComponentType::Tilemap) {
                m_window = window;
                m_file = file;
                m_tileset = tileset;

                std::stringstream ss;
                std::ifstream tilemap(m_file);

                if (!tilemap.is_open()) {
                    Log::error("failed to open tilemap file ", m_file);
                    exit(1);
                }

                if (tilemap) {
                    ss << tilemap.rdbuf();
                }
                tilemap.close();

                u32 i = 0;
                std::string line;

                std::vector<std::pair<i32, std::string>> lines;

                while (std::getline(ss, line)) {
                    if (line != "") {
                        lines.push_back(std::make_pair(i, line));
                    } else {
                        i++;
                    }
                }

                // properties about the tilemap (width,height,layers)
                auto properties = Utils::Strings::split(lines.at(0).second, ',');

                m_rows = std::stoi(properties[0]);
                m_columns = std::stoi(properties[1]);
                m_layers = std::stoi(properties[2]);

                for (i32 i = 0; i < m_layers; i++) {
                    auto v = std::vector<i32>();

                    m_tiles.push_back(v);
                }

                for (i32 i = 0; i < m_layers; i++) {
                    for (i32 j = 0; j < m_rows; j++) {
                        auto line = lines.at(j).second;
                        auto tiles = Utils::Strings::split(line, ',');

                        for (auto tile : tiles) {
						    try {
		                        auto value = std::stoi(tile);

				                m_tiles.at(i).push_back(value);
						    } catch (std::exception ex) {
								Log::error("failed to convert/store tile number, reason ", ex.what());
							}
                        }
                    }
                }
            }

            Tilemap::~Tilemap() {}

            void Tilemap::render() {}

            void Tilemap::render_layer(i32 layer, v2<i32> position) {
				//SDL_RenderCopy(m_window.get(), );
            }

            void Tilemap::render_layer(v3<i32> position) {
                this->render_layer(position[2], v2<i32>(position[0], position[1]));
            }


            i32 Tilemap::at(v3<i32> position) {
                // this engine supports a tilemap with two layers at most
                return 0;
            }


            u32 Tilemap::get_width() { return 0; }
            u32 Tilemap::get_height() { return 0; }
            i32 Tilemap::get_depth() { return 0; }
        }
    }
}
