//
// Created by sneakyfox on 10/17/20.
//

#ifndef XITECH_GLSLLOADER_H
#define XITECH_GLSLLOADER_H


#include "../ResourceLoader.h"
#include "../../graphics/Shader.h"

class GlslLoader : public ResourceLoader {

private:
    unsigned int loadShaderSource(unsigned int shaderType, const std::string &filePath);

public:
    Shader* load(const std::string &filePath) override;
    void load(const std::string &filePath, Resource* shader) override;
};


#endif //XITECH_GLSLLOADER_H
