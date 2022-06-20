//
// Created by apenchev on 5/28/2022.
//

#include "../../include/dom/DomElementAttribute.h"
#include "../../include/helper/FileStreamHelper.h"

/**
 * DomElementAttribute parameter constructor.
 * @param name Name of the DOM attribute
 * @param value Value in the DOM attribute
 */
DomElementAttribute::DomElementAttribute(const String &name, const String &value) : name(name), value(value) {}


DomElementAttribute::DomElementAttribute(std::istream &in) : name(), value() {
    char readBuffer;

    // Get attribute name
    Vector<char> nameDelimiters;
    nameDelimiters.push(' ');
    nameDelimiters.push('=');
    this->name = String(in, nameDelimiters);
    FileStreamHelper::skipWhitespaces(in);

    // TODO: Validate that the name doesn't contain '/' and ' '?

    // Validate there is a '=' in between the name and value
    if (in.get() != '=') {
        throw DomException(DomErrorCode::INVALID_DOM_ATTRIBUTE_FORMAT);
    }

    // Validate the value starts with an opening quote
    FileStreamHelper::skipWhitespaces(in);
    in.read(&readBuffer, sizeof(readBuffer));
    if (readBuffer != '"' && readBuffer != '\'') {
        throw DomException(DomErrorCode::INVALID_DOM_ATTRIBUTE_FORMAT);
    }

    // Get attribute value
    Vector<char> valueDelimiters;
    valueDelimiters.push('"');
    this->value = String(in, valueDelimiters);

    // Validate the value ends with a closing quote
    in.read(&readBuffer, sizeof(readBuffer));
    if (readBuffer != '"' && readBuffer != '\'') {
        throw DomException(DomErrorCode::INVALID_DOM_ATTRIBUTE_FORMAT);
    }
}

/**
 * Output "<<" operator override for output streams.
 * @param out Output stream
 * @param domElementAttribute Reference to a DomElementAttribute object to output
 * @return Output stream reference
 */
std::ostream &operator<<(std::ostream &out, DomElementAttribute &domElementAttribute) {
    return domElementAttribute.serialize(out);
}


bool DomElementAttribute::operator==(const DomElementAttribute &other) const {
    return this->name == other.name && this->value == other.value;
}

bool DomElementAttribute::operator!=(const DomElementAttribute &other) const {
    return this->name != other.name || this->value != other.value;
}

/**
 * DomElementAttribute name getter.
 * @return DomElementAttribute name
 */
String DomElementAttribute::getName() const {
    return this->name;
}

/**
 * DomElementAttribute name setter.
 * @param newName Name to be set
 */
void DomElementAttribute::setName(const String &newName) {
    this->name = newName;
}

/**
 * DomElementAttribute value getter.
 * @return DomElementAttribute value
 */
String DomElementAttribute::getValue() const {
    return this->value;
}

/**
 * DomElementAttribute value setter.
 * @param newValue Value to be set
 */
void DomElementAttribute::setValue(const String &newValue) {
    this->value = newValue;
}

std::ostream &DomElementAttribute::serialize(std::ostream &out) {
    out << this->name << "=\"" << this->value << '"';
    return out;
}
