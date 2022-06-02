//
// Created by apenchev on 5/30/2022.
//

#include <cstring>
#include "../../include/helper/String.h"
#include "../../include/exception/HelperException.h"

/**
 * String parameter constructor.
 * @param value Character array value of the String
 */
String::String(const char *value) : value() {
    this->setValue(value);
}

/**
 * String copy-constructor.
 * @param other Reference to another String object
 */
String::String(const String &other) {
    this->copy(other);
}

/**
 * Equality "=" operator override.
 * @param other Reference to another String object
 * @return Reference to self
 */
String &String::operator=(const String &other) {
    if (this != &other) {
        this->clear();
        this->copy(other);
    }
    return *this;
}

/**
 * Output "<<" operator override for output streams.
 * @param out Output stream
 * @param string Reference to a Book object to output
 * @return Output stream reference
 */
std::ostream &operator<<(std::ostream &out, const String &string) {
    return out << string.getValue();
}

/**
 * String destructor.
 */
String::~String() {
    this->clear();
}

/**
 * String value getter.
 * @return String value
 */
const char *String::getValue() const {
    return this->value;
}

/**
 * String value setter.
 * @param newValue Value to be set
 */
void String::setValue(const char *newValue) {
    // Verifying input is not null
    if (newValue == nullptr) {
        throw HelperException(HelperErrorCode::CANNOT_SET_NULLPTR_AS_VALUE);
    }

    // Allocating memory and copying the input description
    delete[] this->value;
    this->value = new char[std::strlen(newValue) + 1];
    std::strncpy(this->value, newValue, std::strlen(newValue) + 1);
}

/**
 * String value length getter.
 * @return Length of the String value
 */
unsigned int String::getLength() const {
    return std::strlen(this->value);
}

/**
 * Sets object properties from another String object.
 * @param other Reference to another String object
 */
void String::copy(const String &other) {
    this->setValue(other.value);
}

/**
 * Frees dynamically allocated object memory.
 */
void String::clear() {
    delete[] this->value;
    this->value = nullptr;
}
