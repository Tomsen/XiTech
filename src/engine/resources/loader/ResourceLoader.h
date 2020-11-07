//
// Created by sneakyfox on 10/14/20.
//

#ifndef XITECH_RESOURCELOADER_H
#define XITECH_RESOURCELOADER_H

#include <memory>
#include "../Resource.h"

class ResourceLoader {

public:
    virtual Resource* load(const std::string &filePath) = 0;
    virtual void load(const std::string &filePath, Resource* resource) = 0;
};

#endif //XITECH_RESOURCELOADER_H
