//
// Created by sneakyfox on 10/12/20.
//

#include "Mesh.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Mesh::render(Shader *shader) const {

    if(shader != nullptr) {
        glUseProgram(shader->getProgram());
    }

    glBindVertexArray(this->vao);
    glDrawElements(GL_TRIANGLES, this->elements, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);

}

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &elementIndices) {

    this->elements = vertices.size();

    unsigned int VBO;
    unsigned int EBO;

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertices.size(), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glEnableVertexAttribArray(0);


    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*elementIndices.size(), &elementIndices[0], GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}
