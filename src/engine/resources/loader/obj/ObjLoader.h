//
// Created by sneakyfox on 10/14/20.
//

#ifndef XITECH_OBJLOADER_H
#define XITECH_OBJLOADER_H

#include "../ResourceLoaderRegistration.h"
#include "../ResourceLoader.h"
#include "../../graphics/Model.h"

class ObjLoader : public ResourceLoader {

public:
    void load(const std::string &filePath, Resource* model) override;

};

#endif //XITECH_OBJLOADER_H
