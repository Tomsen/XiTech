//
// Created by sneakyfox on 10/10/20.
//


#include "Renderer.h"
#include "../exceptions/GLFWException.h"
#include "../resources/graphics/Model.h"

Renderer::Renderer() {
    this->window = nullptr;
    this->setup();
}

Renderer::~Renderer() {
    glfwTerminate();
}

void Renderer::setup() {

    if(!glfwInit()) {
        throw GLFWException(-1, "Cannot initialize GLFW");
    }

    this->window = glfwCreateWindow(800, 600, "XiTech", nullptr, nullptr);

    if(!this->window) {
        glfwTerminate();
        throw GLFWException(-1, "Could not create Window");
    }

    glfwMakeContextCurrent(this->window);

    gladLoadGL();

}

void Renderer::render() {

    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(this->window);

}

GLFWwindow* Renderer::getWindow() {
    return this->window;
}