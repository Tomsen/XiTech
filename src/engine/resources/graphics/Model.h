//
// Created by sneakyfox on 10/12/20.
//

#ifndef XITECH_MODEL_H
#define XITECH_MODEL_H


#include <vector>
#include "Mesh.h"
#include "../Resource.h"

class Model : public Resource {

private:
    std::vector<Mesh*> meshes = std::vector<Mesh*>();
    std::shared_ptr<Shader> shader;
public:
    explicit Model(const std::string &filePath);
    explicit Model(Mesh* mesh, Shader* _shader);
    ~Model() override;
    static Model load(const std::string &filePath);
    void render();
    void setMeshes(std::vector<Mesh*> &_meshes);
    void setShader(Shader* _shader);
};


#endif //XITECH_MODEL_H
