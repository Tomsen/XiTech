//
// Created by sneakyfox on 10/10/20.
//

#ifndef XITECH_INPUTHANDLER_H
#define XITECH_INPUTHANDLER_H


#include <GLFW/glfw3.h>

class InputHandler {

public:
    InputHandler() = default;
    virtual void handleKeyInput(GLFWwindow* window, int key, int scanCode, int action, int mods) = 0;
    virtual void handleMouseInput(GLFWwindow* window, double xPos, double yPos) = 0;
};


#endif //XITECH_INPUTHANDLER_H
