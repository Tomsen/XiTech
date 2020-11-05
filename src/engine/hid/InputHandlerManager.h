//
// Created by sneakyfox on 10/10/20.
//

#ifndef XITECH_INPUTHANDLERMANAGER_H
#define XITECH_INPUTHANDLERMANAGER_H


#include <vector>
#include "InputHandler.h"

class InputHandlerManager {

private:
    InputHandlerManager() = default;
    static InputHandlerManager* instance;
    static std::vector<InputHandler*> handlers;
    static InputHandler* activeHandler;
public:
    static void registerHandler(InputHandler* inputHandler, bool bSetActive);
    static void handleKeyboard(GLFWwindow* window, int key, int scanCode, int action, int mods);
    static void handleMouse(GLFWwindow* window, double xPos, double yPos);
};


#endif //XITECH_INPUTHANDLERMANAGER_H
