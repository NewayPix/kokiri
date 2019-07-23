#include "wavefront_loader.hpp"

#include <glm/glm.hpp>

WavefrontLoader::WavefrontLoader() {

}

WavefrontLoader::WavefrontLoader(const std::string &path) {

}

WavefrontLoader::~WavefrontLoader() {

}

Object WavefrontLoader::load() {
    return Object();
}

Object WavefrontLoader::load(const std::string &path) {
    Object obj;
    std::ifstream file(path);

    if(!file.is_open()){
        std::cout << "The file could not be read. Verify if the file exists."
                  << std::endl;;
        return Object();
    }

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec3> faces;

    double x, y, z;
    //
    std::string type;
    std::string name;

   while(file >> type) {
        if (type == "o") {
            file >> name;
        }
        if (type == "v") {
            file >> x >> y >> z;

            glm::vec3 v(x, y, z);
            vertices.push_back(v);
        } else if (type == "vn") {
            file >> x >> y >> z;

            glm::vec3 v(x, y, z);
            normals.push_back(v);
        } else if (type == "f") {
            // TODO: Implement this piece of code.
        }
   }

    obj.name = name;
    obj.normals = normals;
    obj.vertices = vertices;

    return obj;
}
