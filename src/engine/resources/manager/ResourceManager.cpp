//
// Created by sneakyfox on 10/12/20.
//

#include "ResourceManager.h"
#include "../exceptions/ResourceException.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::~ResourceManager() {
}

ResourceManager& ResourceManager::get() {
    if(instance != nullptr) {
        return *instance;
    }
    instance = new ResourceManager();
    return *instance;
}

ResourceLoader *ResourceManager::getLoader(const std::string &filePath) {

    auto index = filePath.find_last_of('.');
    auto fileType = filePath.substr(index+1);

    auto loader = this->loaders.find(fileType);

    if(loader != this->loaders.end()) {
        return loader->second;
    }  else {
        return nullptr;
    }
}

std::shared_ptr<Resource> ResourceManager::getResource(const std::string &filePath, Resource* resourceInstance) {

    auto resource = this->resources.find(filePath);

    if(resource != this->resources.end()) {
        return resource->second;
    }

    ResourceLoader* loader = this->getLoader(filePath);

    if(loader != nullptr) {
        loader->load(filePath, resourceInstance);
        auto loadedResource = std::make_shared<Resource>(*resourceInstance);
        this->resources.insert(std::pair<std::string, std::shared_ptr<Resource>>(filePath, loadedResource));
        return loadedResource;
    }

    throw ResourceException("No ResourceLoader found");

}

void ResourceManager::registerLoader(const std::string &fileType, ResourceLoader *resourceLoader) {

    if(this->loaders.find(fileType) == this->loaders.end()) {
        this->loaders.insert(std::pair<std::string, ResourceLoader*>(fileType, resourceLoader));
    }

}
