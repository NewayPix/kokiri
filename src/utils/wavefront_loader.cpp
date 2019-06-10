#include "wavefront_loader.hpp"

#include <glm/glm.hpp>

struct a_t{
    char a;
    int b;
    char padding[3];
};


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
        std::cout << "O arquivo não pode ser lido. Verifique se o arquivo existe." << std::endl;;
        return;
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
            Vector3<float> v(x, y, z);
            vertices.push_back(v);
        } else if (type == "vn") {
            file >> x >> y >> z;

            glm::vec3 v(x, y, z);
            normals.push_back(v);
        } else if (type == "f") {

        }
	}

    obj.name = name;
    obj.normals = normals;
    obj.vertices = vertices;

    return obj;
}
