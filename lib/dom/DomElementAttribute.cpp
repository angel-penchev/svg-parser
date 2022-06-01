//
// Created by apenchev on 5/28/2022.
//

#include "../../include/dom/DomElementAttribute.h"

/**
 * DomElementAttribute parameter constructor.
 * @param name Name of the DOM attribute
 * @param value Value in the DOM attribute
 */
DomElementAttribute::DomElementAttribute(const String &name, const String &value) : name(name), value(value) {}

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
