//
// Created by sneakyfox on 10/14/20.
//

#ifndef XITECH_RESOURCELOADERREGISTRATION_H
#define XITECH_RESOURCELOADERREGISTRATION_H

#include <string>

#include "../manager/ResourceManager.h"

namespace XiTechRegistration {

    template <typename T>
    class ResourceLoaderRegistration {
        public:
            ResourceLoaderRegistration(const std::string &fileType) {
                ResourceManager::get().registerLoader(fileType, new T());
            }
    };

}

#endif //XITECH_RESOURCELOADERREGISTRATION_H
