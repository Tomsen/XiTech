//
// Created by sneakyfox on 10/10/20.
//

#ifndef XITECH_RENDERER_H
#define XITECH_RENDERER_H

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "../resources/graphics/Model.h"

class Renderer {

private:
    GLFWwindow* window;

public:
    Renderer();
    ~Renderer();
    void setup();
    void render();
    GLFWwindow* getWindow();
};


#endif //XITECH_RENDERER_H
