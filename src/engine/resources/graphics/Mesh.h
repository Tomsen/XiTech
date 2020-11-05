//
// Created by sneakyfox on 10/12/20.
//

#ifndef XITECH_MESH_H
#define XITECH_MESH_H

#include <vector>
#include "../../math/Vector.h"
#include "Shader.h"
#include "Vertex.h"

class Mesh {

private:
    unsigned int vao;
    unsigned int elements;

public:
    Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &elementIndices);
    void render(Shader *shader) const;
};


#endif //XITECH_MESH_H
