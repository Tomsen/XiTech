//
// Created by sneakyfox on 10/12/20.
//

#include "ResourceManager.h"
#include "../exceptions/ResourceException.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::~ResourceManager() {
    for (auto & loader : this->loaders) {
        delete loader.second;
    }
}

ResourceManager ResourceManager::get() {
    if(instance != nullptr) {
        return *instance;
    }
    instance = new ResourceManager();
    return *instance;
}

ResourceLoader *ResourceManager::getLoader(const std::string &filePath) {

    auto index = filePath.find_last_of('.');
    auto fileType = filePath.substr(index);

    return this->loaders.find(fileType)->second;

}

std::shared_ptr<Resource> ResourceManager::getResource(const std::string &filePath, Resource* resource) {

    auto resource = this->resources.find(filePath);

    if(resource != this->resources.end()) {
        return resource->second;
    }

    ResourceLoader* loader = this->getLoader(filePath);

    if(loader != nullptr) {
        auto loadedResource = std::make_shared<Resource>(*loader->load(filePath));
        this->resources[filePath] = loadedResource;
        return loadedResource;
    }

    throw ResourceException("No ResourceLoader found");

}

void ResourceManager::registerLoader(const std::string &fileType, ResourceLoader *resourceLoader) {

    if(this->loaders.find(fileType) == this->loaders.end()) {
        this->loaders[fileType] = resourceLoader;
    }

}
