//
// Created by sneakyfox on 10/15/20.
//

#include "Shader.h"
#include "../manager/ResourceManager.h"

unsigned int Shader::getProgram() const {
    return this->program;
}

void Shader::setProgram(unsigned int _program) {
    this->program = _program;
}

Shader::Shader(const std::string &filePath) {
    ResourceManager::get().getResource(filePath, this);
}
