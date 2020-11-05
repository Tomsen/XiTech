//
// Created by sneakyfox on 10/15/20.
//

#ifndef XITECH_VECTOR2_H
#define XITECH_VECTOR2_H

template <typename T>
class Vector2 {
public:
    T x, y;
    Vector2() = default;
    Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    };
};


#endif //XITECH_VECTOR2_H
