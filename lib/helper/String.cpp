//
// Created by apenchev on 5/30/2022.
//

#include <cstring>
#include <iostream>
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
 * String input file constructor.
 * Reads the information for a String value (until a delimiter) from a file and constructs a String object based on it.
 * @param in Input file stream
 * @param delimiters Delimiters, indicating the end of the String
 */
String::String(std::istream &in, Vector<char> delimiters) {
    char readBuffer[MAX_STRING_LEN];
    char currentChar;
    unsigned char valueLength = 0;

    // Read string value from the input stream until a delimiter is reached or eof
    while (in) {
        in.read(&currentChar, 1);

        if (delimiters.contains(currentChar)) {
            readBuffer[valueLength++] = '\0';
            break;
        }

        readBuffer[valueLength++] = currentChar;
    }

    // Store the read string value
    this->value = new char[valueLength];
    std::strncpy(this->value, readBuffer, valueLength);

    // Offset the filestream cursor by 1 position back
    in.seekg(-1, std::ios::cur);
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
 * @param string Reference to a String object to output
 * @return Output stream reference
 */
std::ostream &operator<<(std::ostream &out, const String &string) {
    return out << string.getValue();
}

/**
 * Addition "+" operator override.
 * @param other Reference to a String to be appended
 */
String String::operator+(const String &other) const {
    return this->concatenate(other);
}

/**
 * Equality "==" operator override.
 * @param other Reference to a String to be compared with
 * @return Whether the Strings are the same or not
 */
bool String::operator==(const String &other) const {
    return !std::strcmp(this->value, other.value);
}

/**
 * Inequality "!=" operator override.
 * @param other Reference to a String to be compared with
 * @return Whether the Strings are not the same
 */
bool String::operator!=(const String &other) const {
    return std::strcmp(this->value, other.value);
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
        throw HelperException(HelperErrorCode::CANNOT_SET_NULLPTR_AS_HELPER_VALUE);
    }

    // Clearing previously allocated memory, allocating new memory and copying the string value
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
 * Concatenates the current string with another.
 * @param other Other string to be appended
 * @return String which has both strings concatenated
 */
String String::concatenate(const String &other) const {
    // Create a new value buffer long enough to hold both strings and a '\0'
    unsigned int combinedLength = this->getLength() + other.getLength() + 1;
    char *combinedContents = new char[combinedLength];

    // Copy this string and other string to one array
    std::strncpy(combinedContents, this->getValue(), this->getLength() + 1);
    std::strcat(combinedContents, other.getValue());

    String result(combinedContents);
    delete[] combinedContents;

    return result;
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

bool String::getLine(std::istream &in, const char delimiter) {
    char readBuffer[MAX_STRING_LEN];
    bool result = (bool) in.getline(readBuffer, MAX_STRING_LEN, delimiter);

    // Store the read string value
    delete this->value;
    this->value = new char[std::strlen(readBuffer) + 1];
    std::strncpy(this->value, readBuffer, std::strlen(readBuffer) + 1);

    return result;
}

double String::toDouble() {
    return std::strtold(this->value, nullptr);
}
