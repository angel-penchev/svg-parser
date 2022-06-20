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
    explicit Vector(unsigned int capacity = DEFAULT_CAPACITY);

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

    T *find(T element) const;

    bool contains(T element) const;
};

/**
 * Vector parameter constructor.
 * @tparam T Vector contents type
 * @param capacity Desired vector capacity
 */
template<typename T>
Vector<T>::Vector(unsigned int capacity)
        : size(0), capacity(capacity >= DEFAULT_CAPACITY ? capacity : DEFAULT_CAPACITY), array(new T[this->capacity]) {}

/**
 * Vector copy-constructor.
 * @tparam T Vector contents type
 * @param other Reference to another Vector object
 */
template<typename T>
Vector<T>::Vector(const Vector &other) : size(), capacity(), array() {
    this->copy(other);
}

/**
* Equality "=" operator override.
* @tparam T Vector contents type
* @param other Reference to another String object
* @return Reference to self
*/
template<typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this != &other) {
        this->clear();
        this->copy(other);
    }
    return *this;
}

/**
 * Subscript "[]" operator override.
 * @tparam T Vector contents type
 * @param index Index of the element in the Vector
 * @return Reference to the Vector element
 */
template<typename T>
T &Vector<T>::operator[](unsigned int index) {
    return this->at(index);
}

/**
 * Const subscript "[]" operator override.
 * @tparam T Vector contents type
 * @param index Index of the element in the Vector
 * @return Constant reference to the Vector element
 */
template<typename T>
const T &Vector<T>::operator[](unsigned int index) const {
    return this->at(index);
}

/**
 * Vector destructor.
 * @tparam T Vector contents type
 */
template<typename T>
Vector<T>::~Vector() {
    this->clear();
}

/**
 * Appends a new element to the end of the Vector.
 * @tparam T Vector contents type
 * @param element Element to be appended
 */
template<typename T>
void Vector<T>::push(const T &element) {
    // Reserve capacity if the array is not big enough to handle the new element
    if (this->size >= this->capacity) {
        this->reserve(2 * this->capacity);
    }

    // Append the new element and increase the size
    this->array[this->size++] = element;
}

/**
 * Removes an element from the Vector.
 * @tparam T Vector contents type
 * @param index Index of the element to be removed
 */
template<typename T>
void Vector<T>::erase(unsigned int index) {
    // Reduce the array size and move every element after the removed to the left
    for (unsigned int i = index; i < --this->size; i++) {
        this->array[i] = this->array[i + 1];
    }
}

/**
 * Allocates space for bigger Vector capacities.
 * @tparam T Vector contents type
 * @param reserveCapacity Desired capacity
 */
template<typename T>
void Vector<T>::reserve(unsigned int reserveCapacity) {
    if (reserveCapacity > this->capacity) {
        // Create a new array with the bigger a bigger capacity
        this->capacity = reserveCapacity;
        T *newArray = new T[this->capacity];

        // Copy elements to the new array
        for (unsigned int i = 0; i < this->size; i++) {
            newArray[i] = this->array[i];
        }

        // Replace the Vector array with the new array
        delete[] this->array;
        this->array = newArray;
    }
}

/**
 * Vector size getter.
 * @tparam T Vector contents type
 * @return Vector size
 */
template<typename T>
unsigned int Vector<T>::getSize() const {
    return this->size;
}

/**
 * Vector capacity getter.
 * @tparam T Vector contents type
 * @return Vector capacity
 */
template<typename T>
unsigned int Vector<T>::getCapacity() const {
    return this->capacity;
}

/**
 * Gets an reference to an element from the Vector.
 * @tparam T Vector contents type
 * @param index Index of the element in Vector
 * @return Reference to an element in the Vector
 */
template<typename T>
T &Vector<T>::at(unsigned int index) noexcept(false) {
    if (index >= this->size) {
        throw HelperException(HelperErrorCode::INDEX_OUT_OF_INDEX);
    }
    return this->array[index];
}

/**
 * Gets an constant reference to an element from the Vector.
 * @tparam T Vector contents type
 * @param index Index of the element in Vector
 * @return Constant reference to an element in the Vector
 */
template<typename T>
const T &Vector<T>::at(unsigned int index) const noexcept(false) {
    if (index >= this->size) {
        throw HelperException(HelperErrorCode::INDEX_OUT_OF_INDEX);
    }
    return this->array[index];
}

template<typename T>
T *Vector<T>::find(T element) const {
    for (unsigned int i = 0; i < this->size; i++) {
        if (this->array[i] == element) {
            return &this->array[i];
        }
    }
    return nullptr;
}

template<typename T>
bool Vector<T>::contains(T element) const {
    return this->find(element) != nullptr;
}

/**
* Sets object properties from another Vector object.
* @tparam T Vector contents type
* @param other Reference to another Vector object
*/
template<typename T>
void Vector<T>::copy(const Vector &other) {
    this->size = other.size;
    this->capacity = other.capacity;

    delete[] this->array;
    this->array = new T[this->capacity];
    for (unsigned int i = 0; i < this->size; i++) {
        this->array[i] = other.array[i];
    }
}

/**
 * Frees dynamically allocated object memory.
 * @tparam T Vector contents type
 */
template<typename T>
void Vector<T>::clear() {
    delete[] this->array;
    this->array = nullptr;
}

#endif //SVG_PARSER_VECTOR_H
