//
// Created by sneakyfox on 10/15/20.
//

#ifndef XITECH_SHADER_H
#define XITECH_SHADER_H


#include "../Resource.h"

class Shader : public Resource {

private:
    unsigned int program;
public:
    void setProgram(unsigned int program);
    [[nodiscard]] unsigned int getProgram() const;
};


#endif //XITECH_SHADER_H
