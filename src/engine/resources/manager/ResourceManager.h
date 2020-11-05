//
// Created by sneakyfox on 10/12/20.
//

#ifndef XITECH_RESOURCEMANAGER_H
#define XITECH_RESOURCEMANAGER_H


#include <vector>
#include <map>
#include <memory>
#include "../loader/ResourceLoader.h"
#include "../Resource.h"

class ResourceManager {

private:
    std::map<std::string, ResourceLoader*> loaders = std::map<std::string, ResourceLoader*>();
    std::map<std::string, std::shared_ptr<Resource>> resources = std::map<std::string, std::shared_ptr<Resource>>();
    static ResourceManager* instance;
    ResourceManager() = default;

public:
    ~ResourceManager();
    static ResourceManager get();
    void registerLoader(const std::string &fileType, ResourceLoader *resourceLoader);
    ResourceLoader* getLoader(const std::string &filePath);
    std::shared_ptr<Resource> getResource(const std::string &filePath);
};


#endif //XITECH_RESOURCEMANAGER_H
