//
// Created by sneakyfox on 10/10/20.
//

#ifndef XITECH_XITECH_H
#define XITECH_XITECH_H


#include "rendering/Renderer.h"

class XiTech {

private:
    XiTech();
    static XiTech* instance;
    Renderer renderer{};
    void run();
public:
    ~XiTech() = default;
    static XiTech getInstance();
    void start();
};


#endif //XITECH_XITECH_H
