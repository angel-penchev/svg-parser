//
// Created by apenchev on 5/30/2022.
//

#ifndef SVG_PARSER_VECTOR_H
#define SVG_PARSER_VECTOR_H

#include "../exception/HelperException.h"

#define DEFAULT_CAPACITY 4

template<typename T>
class Vector {
private:
    unsigned int size;
    unsigned int capacity;
    T *array;

    void copy(const Vector &other);

    void clear();

public:
    explicit Vector(unsigned int capacity = 0);

    Vector(const Vector &other);

    Vector &operator=(const Vector &other);

    T &operator[](unsigned int index);

    const T &operator[](unsigned int index) const;

    virtual ~Vector();

    void push(const T &element);

    void erase(unsigned int index);

    void reserve(unsigned int reserveCapacity);

    unsigned int getSize() const;

    unsigned int getCapacity() const;

    T &at(unsigned int index) noexcept(false);

    const T &at(unsigned int index) const noexcept(false);
};


#endif //SVG_PARSER_VECTOR_H
