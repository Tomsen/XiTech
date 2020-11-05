//
// Created by sneakyfox on 10/17/20.
//

#include "glad/glad.h"
#include <fstream>
#include "GlslLoader.h"
#include "../../exceptions/ResourceException.h"

Shader *GlslLoader::load(const std::string &filePath) {

    auto dotIndex = filePath.find_last_of(".");
    auto cleanPath = filePath.substr(0, dotIndex);
    auto vertSourcePath = cleanPath + ".vert";
    auto fragSourcePath = cleanPath + ".frag";

    unsigned int vertShader = this->loadShaderSource(GL_VERTEX_SHADER, vertSourcePath);
    unsigned int fragShader = this->loadShaderSource(GL_FRAGMENT_SHADER, fragSourcePath);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        throw ResourceException(infoLog);
    }

    auto* shader = new Shader();
    shader->setProgram(shaderProgram);
    return shader;

}

unsigned int GlslLoader::loadShaderSource(unsigned int shaderType, const std::string filePath) {

    std::ifstream file(filePath);
    std::string source((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
    file.close();

    unsigned int shader;
    const char* sourcePointer = source.c_str();

    shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &sourcePointer, nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        throw ResourceException(infoLog);
    }

    return shader;

}
