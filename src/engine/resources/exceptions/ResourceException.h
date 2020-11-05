//
// Created by sneakyfox on 10/14/20.
//

#ifndef XITECH_RESOURCEEXCEPTION_H
#define XITECH_RESOURCEEXCEPTION_H


#include <exception>
#include <string>

class ResourceException : public std::exception {

private:
    std::string cause;
public:
    explicit ResourceException(const std::string &cause);

    explicit ResourceException(const char* cause);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};


#endif //XITECH_RESOURCEEXCEPTION_H
