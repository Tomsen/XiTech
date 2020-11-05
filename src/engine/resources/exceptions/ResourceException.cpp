//
// Created by sneakyfox on 10/14/20.
//

#include "ResourceException.h"

ResourceException::ResourceException(const std::string &cause) {
    this->cause = cause;
}

ResourceException::ResourceException(const char *cause) {
    this->cause = cause;
}

const char *ResourceException::what() const noexcept {
    return this->cause.c_str();
}