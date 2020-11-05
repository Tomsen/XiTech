//
// Created by sneakyfox on 10/16/20.
//

#ifndef XITECH_VERTEX_H
#define XITECH_VERTEX_H

#include "../../math/Vector.h"

class Vertex {

private:
    Vector3<float> position;
    Vector3<float> normal;
    Vector2<float> uv;

public:
    Vertex(Vector3<float> *position, Vector3<float> *normal, Vector2<float> *uv);
};


#endif //XITECH_VERTEX_H
