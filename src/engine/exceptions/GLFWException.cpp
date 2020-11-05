//
// Created by sneakyfox on 10/10/20.
//

#include "GLFWException.h"

#include <utility>

GLFWException::GLFWException(int errorCode, std::string message) {
    this->errorCode = errorCode;
    this->message = std::move(message);
}
