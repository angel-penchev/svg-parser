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
