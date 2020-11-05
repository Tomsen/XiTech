//
// Created by sneakyfox on 10/10/20.
//

#ifndef XITECH_GLFWEXCEPTION_H
#define XITECH_GLFWEXCEPTION_H

#include <string>

class GLFWException : public std::exception {

private:
    std::string message;
    int errorCode;

public:
    GLFWException(int errorCode, std::string message);
};


#endif //XITECH_GLFWEXCEPTION_H
