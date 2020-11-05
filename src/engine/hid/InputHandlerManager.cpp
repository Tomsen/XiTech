//
// Created by sneakyfox on 10/10/20.
//

#include "InputHandlerManager.h"

InputHandlerManager* InputHandlerManager::instance = nullptr;
std::vector<InputHandler*> InputHandlerManager::handlers = std::vector<InputHandler*>();
InputHandler* InputHandlerManager::activeHandler = nullptr;

void InputHandlerManager::registerHandler(InputHandler* inputHandler, bool setActive) {

    auto element = std::find(handlers.begin(), handlers.end(), inputHandler);

    if(element != handlers.end()) {
        inputHandler = *element;
    } else {
        handlers.push_back(inputHandler);
    }

    if(setActive) {
        activeHandler = inputHandler;
    }

}

void InputHandlerManager::handleKeyboard(GLFWwindow *window, int key, int scanCode, int action, int mods) {
    if(activeHandler != nullptr) {
        activeHandler->handleKeyInput(window, key, scanCode, action, mods);
    }
}

void InputHandlerManager::handleMouse(GLFWwindow *window, double xPos, double yPos) {
    if(activeHandler != nullptr) {
        activeHandler->handleMouseInput(window, xPos, yPos);
    }
}