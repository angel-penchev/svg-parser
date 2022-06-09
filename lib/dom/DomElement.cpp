//
// Created by apenchev on 5/28/2022.
//

#include "../../include/dom/DomElement.h"

DomElement::DomElement(const String &tag, const Vector<DomElementAttribute> &attributes, DomElement *child)
        : tag(tag), attributes(attributes), child() {
    this->setChild(child);
}

DomElement::DomElement(const DomElement &other) : tag(), attributes(), child() {
    this->copy(other);
}

DomElement::DomElement(std::istream &in) : tag(), attributes(), child() {
    char readBuffer;

    // Validate the element starts with an '<'
    in.read(&readBuffer, sizeof(readBuffer));
    if (readBuffer != '<') {
        throw DomException(DomErrorCode::INVALID_DOM_ELEMENT_FORMAT);
    }

    // Get tag name
    this->tag = String(in, ' ');

    // Get all attributes
    int i = 0;
    while (in.peek() != '/' && in.peek() != '>') {
        this->attributes.push(DomElementAttribute(in));
        std::cout << this->attributes[i++].getName() << '\n';
        in.get(); // TODO: Skip multiple whitespaces
    }

    // Get child
    in.read(&readBuffer, sizeof(readBuffer));
    if (readBuffer == '>') {
        this->child = new DomElement(in);
    }
}

DomElement &DomElement::operator=(const DomElement &other) {
    if (this != &other) {
        this->clear();
        this->copy(other);
    }
    return *this;
}

DomElement::~DomElement() {
    this->clear();
}

const String &DomElement::getTag() const {
    return this->tag;
}

void DomElement::setTag(const String &newTag) {
    this->tag = newTag;
}

const Vector<DomElementAttribute> &DomElement::getAttributes() const {
    return this->attributes;
}

void DomElement::setAttributes(const Vector<DomElementAttribute> &newAttributes) {
    this->attributes = newAttributes;
}

DomElement *DomElement::getChild() const {
    return this->child;
}

void DomElement::setChild(const DomElement *newChild) {
    // Verifying input is not null
    if (newChild == nullptr) {
        throw DomException(DomErrorCode::CANNOT_SET_NULLPTR_AS_DOM_VALUE);
    }

    // Deleting old child and copying the new child in its place
    delete this->child;
    this->child = new DomElement(*newChild);
}

void DomElement::copy(const DomElement &other) {
    this->tag = other.tag;
    this->attributes = other.attributes;
    this->setChild(other.child);
}

void DomElement::clear() {
    delete this->child;
    this->child = nullptr;
}
