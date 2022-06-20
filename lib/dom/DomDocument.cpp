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
    this->parentElement = new DomElement(file);

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

DomElement *DomDocument::getParentElement() const {
    return this->parentElement;
}

void DomDocument::setParentElement(DomElement *newParentElement) {
    this->parentElement = newParentElement;
}

void DomDocument::copy(const DomDocument &other) {
    this->setFilename(filename);
    this->parentElement = other.parentElement;
}

void DomDocument::clear() {
    delete this->parentElement;
}
