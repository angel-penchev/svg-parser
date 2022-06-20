//
// Created by apenchev on 5/28/2022.
//

#include "../../include/dom/DomElement.h"
#include "../../include/helper/FileStreamHelper.h"

DomElement::DomElement(const String &tag, const Vector<DomElementAttribute> &attributes,
                       const Vector<DomElement *> &children) : tag(tag), attributes(attributes), children(children) {}


DomElement::DomElement(std::istream &in) : tag(), attributes(), children() {
    // Validate the element starts with an '<'
    if (in.get() != '<') {
        throw DomException(DomErrorCode::INVALID_DOM_ELEMENT_FORMAT);
    }

    // Get tag name
    Vector<char> tagDelimiters;
    tagDelimiters.push(' ');
    tagDelimiters.push('>');
    this->tag = String(in, tagDelimiters);

    // Get all attributes
    while (in.peek() != '/' && in.peek() != '>') {
        this->attributes.push(DomElementAttribute(in));
        FileStreamHelper::skipWhitespaces(in);
    }

    // Get children if the tag is not self-closing
    if (in.get() == '>') {
        while (FileStreamHelper::peekWithOffset(in, 2) != '/') {
            this->children.push(new DomElement(in));
        };

        // Validate the element has a closing tag
        Vector<char> closingTagDelimiters;
        closingTagDelimiters.push('>');
        String closingTag(in, closingTagDelimiters);
        String expectedClosingTag = String("</") + String(this->tag);
        if (closingTag != expectedClosingTag) {
            throw DomException(DomErrorCode::INVALID_DOM_ELEMENT_FORMAT);
        }
    } else {
        // Validate the element ends with '>'
        if (in.get() != '>') {
            throw DomException(DomErrorCode::INVALID_DOM_ELEMENT_FORMAT);
        }
    }
}

DomElement::DomElement(const DomElement &other) {
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

const Vector<DomElement *> &DomElement::getChildren() const {
    return this->children;
}

void DomElement::setChildren(const Vector<DomElement *> &newChildren) {
    this->children = newChildren;
}

void DomElement::copy(const DomElement &other) {
    this->setTag(tag);
    this->setAttributes(attributes);
    for (unsigned int i = 0; i < other.children.getSize(); i++) {
        this->children[i] = other.children[i];
    }
}

void DomElement::clear() {
    for (unsigned int i = 0; i < this->children.getSize(); i++) {
        delete this->children[i];
    }
}
