//
// Created by sneakyfox on 10/16/20.
//

#include "Vertex.h"

Vertex::Vertex(Vector3<float> *position, Vector3<float> *normal, Vector2<float> *uv) {
    this->position = *position;
    this->normal = *normal;
    this->uv = *uv;
}
