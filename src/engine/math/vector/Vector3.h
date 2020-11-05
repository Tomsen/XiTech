//
// Created by sneakyfox on 10/15/20.
//

#ifndef XITECH_VECTOR3_H
#define XITECH_VECTOR3_H

template <typename T>
class Vector3 {

public:
    T x, y, z;
    Vector3() = default;
    Vector3(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };
};



#endif //XITECH_VECTOR3_H
