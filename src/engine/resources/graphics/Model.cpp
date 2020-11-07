//
// Created by sneakyfox on 10/12/20.
//

#include "Model.h"

#include <utility>
#include "../manager/ResourceManager.h"

Model::Model(const std::string &filePath) {
    ResourceManager::get().getResource(filePath, this);
}

Model::Model(Mesh *mesh, Shader* _shader) {
    this->meshes.push_back(mesh);
    this->shader = std::make_shared<Shader>(*_shader);
}

Model::~Model() {
    for(auto mesh : this->meshes) {
        delete mesh;
    }
}

void Model::setShader(Shader *_shader) {
    this->shader = std::make_shared<Shader>(*_shader);
}

void Model::setMeshes(std::vector<Mesh *> &_meshes) {
    this->meshes = _meshes;
}

void Model::render() {
    for(auto mesh : this->meshes) {
        mesh->render(this->shader.get());
    }
}

