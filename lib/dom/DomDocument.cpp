//
// Created by apenchev on 5/28/2022.
//

#include "../../include/dom/DomDocument.h"
#include "../../include/helper/FileStreamHelper.h"

DomDocument::DomDocument() : parentElement(nullptr) {}

DomDocument::DomDocument(const String &filename) : filename(filename) {
    // Open DOM file
    std::ifstream in(filename.getValue(), std::ios::in);
    if (!in) {
        throw DomException(DomErrorCode::CANNOT_SET_NULLPTR_AS_DOM_VALUE);
    }
    FileStreamHelper::skipWhitespaces(in);

    // Read xml version tag
    Vector<char> tagDelimiters;
    tagDelimiters.push('\n');
    tagDelimiters.push('\r');
    this->versionTag = String(in, tagDelimiters);
    FileStreamHelper::skipWhitespaces(in);

    // Read doctype tag
    this->doctypeTag = String(in, tagDelimiters);
    FileStreamHelper::skipWhitespaces(in);

    // Read all parent elements in DOM tree
    this->parentElement = new DomElement(in);

    // Close the DOM file
    in.close();
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

void DomDocument::save() {
    std::ofstream out(this->filename.getValue(), std::ios::out | std::ios::trunc);
    this->serialize(out);
}

void DomDocument::saveAs(String &filepath) {
    std::ofstream out(filepath.getValue(), std::ios::out | std::ios::trunc);
    this->serialize(out);
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

std::ostream &DomDocument::serialize(std::ostream &out) {
    return out << this->versionTag << '\n' << this->doctypeTag << '\n' << *this->parentElement;
}

void DomDocument::copy(const DomDocument &other) {
    this->setVersionTag(other.versionTag);
    this->setDoctypeTag(other.doctypeTag);
    this->setFilename(other.filename);
    this->setParentElement(other.parentElement);
}

void DomDocument::clear() {
    delete this->parentElement;
    this->parentElement = nullptr;
}
