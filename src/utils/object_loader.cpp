#include "object_loader.hpp"

ObjectLoader::ObjectLoader() {

}

ObjectLoader::ObjectLoader(const std::string &path) {

}

ObjectLoader::~ObjectLoader() {

}

Object ObjectLoader::load() {
    return Object();
}

Object ObjectLoader::load(const std::string &path) {
    Object dummy;

    // TODO: Load the object (Julio's task)

    return dummy;
}
