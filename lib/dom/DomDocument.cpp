//
// Created by apenchev on 5/28/2022.
//

#include "../../include/dom/DomDocument.h"
#include "../../include/helper/FileStreamHelper.h"

DomDocument::DomDocument(const String &filename) : filename(filename) {
    // Open DOM file
    std::ifstream file(filename.getValue(), std::ios::in);
    if (!file) {
        throw DomException(DomErrorCode::CANNOT_SET_NULLPTR_AS_DOM_VALUE);
    }
    FileStreamHelper::skipWhitespaces(file);

    // Read xml version tag
    this->versionTag.getLine(file);
    FileStreamHelper::skipWhitespaces(file);

    // Read doctype tag
    this->doctypeTag.getLine(file);
    FileStreamHelper::skipWhitespaces(file);

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

const String &DomDocument::getVersionTag() const {
    return this->versionTag;
}

void DomDocument::setVersionTag(const String &newVersionTag) {
    this->versionTag = newVersionTag;
}

const String &DomDocument::getDoctypeTag() const {
    return this->doctypeTag;
}

void DomDocument::setDoctypeTag(const String &newDoctypeTag) {
    this->doctypeTag = newDoctypeTag;
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
    delete this->parentElement;
    this->parentElement = newParentElement;
}

void DomDocument::copy(const DomDocument &other) {
    this->setFilename(filename);
    this->parentElement = other.parentElement;
}

void DomDocument::clear() {
    delete this->parentElement;
    this->parentElement = nullptr;
}
