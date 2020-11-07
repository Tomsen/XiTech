//
// Created by sneakyfox on 10/10/20.
//

#include "XiTech.h"
#include "hid/InputHandlerManager.h"

XiTech* XiTech::instance = nullptr;

XiTech::XiTech() {
    glfwSetKeyCallback(this->renderer.getWindow(), InputHandlerManager::handleKeyboard);
    glfwSetCursorPosCallback(this->renderer.getWindow(), InputHandlerManager::handleMouse);
}

XiTech XiTech::getInstance() {
    if(instance == nullptr) {
        instance = new XiTech();
    }
    return *instance;
}

void XiTech::run() {

    while(!glfwWindowShouldClose(this->renderer.getWindow())) {

        this->renderer.render();

        glfwPollEvents();

    }

}

void XiTech::start() {
    this->run();
}