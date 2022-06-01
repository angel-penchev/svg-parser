//
// Created by apenchev on 5/30/2022.
//

#ifndef SVG_PARSER_EXCEPTION_H
#define SVG_PARSER_EXCEPTION_H


#include <exception>

template<typename T>
class Exception : public std::exception {
public:
    T errorCode;
public:
    explicit Exception(T errorCode);

    T getErrorCode() const;

    virtual const char *getErrorMessage() const = 0;

    const char *what() const noexcept override;
};

template<typename T>
Exception<T>::Exception(T errorCode) : errorCode(errorCode) {}

template<typename T>
T Exception<T>::getErrorCode() const {
    return this->errorCode;
}

template<typename T>
const char *Exception<T>::what() const noexcept {
    return this->getErrorMessage();
}


#endif //SVG_PARSER_EXCEPTION_H
