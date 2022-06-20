//
// Created by apenchev on 5/28/2022.
//

#include "../../include/dom/DomDocument.h"

DomDocument::DomDocument(const String &filename) : filename(filename) {
    // Open DOM file
    std::ifstream file(filename.getValue(), std::ios::in);
    if (!file) {
        throw DomException(DomErrorCode::CANNOT_SET_NULLPTR_AS_DOM_VALUE);
    }

    // Read all parent elements in DOM tree
    while (file.peek() != -1) {
        this->elements.push(new DomElement(file));
    }

    // Close the DOM file
    file.close();
}

DomDocument::DomDocument(const DomDocument &other) {
    this->copy(other);
}

DomDocument &DomDocument::operator=(const DomDocument &other) {
    if (this != &other) {
        this->clear();
        this->copy(other);
    }
    return *this;
}

DomDocument::~DomDocument() {
    this->clear();
}

void DomDocument::serialize(std::ostream out) {
    // TODO: Serialize
}

const String &DomDocument::getFilename() const {
    return this->filename;
}

void DomDocument::setFilename(const String &newFilename) {
    this->filename = newFilename;
}

const Vector<DomElement *> &DomDocument::getElements() const {
    return this->elements;
}

void DomDocument::setElements(const Vector<DomElement *> &newElements) {
    this->elements = newElements;
}

void DomDocument::copy(const DomDocument &other) {
    this->setFilename(filename);
    for (unsigned int i = 0; i < other.elements.getSize(); i++) {
        this->elements[i] = other.elements[i];
    }
}

void DomDocument::clear() {
    for (unsigned int i = 0; i < this->elements.getSize(); i++) {
        delete this->elements[i];
    }
}
