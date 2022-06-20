//
// Created by apenchev on 5/28/2022.
//

#include "../../include/dom/DomElement.h"
#include "../../include/helper/FileStreamHelper.h"

DomElement::DomElement(const String &tag, const Vector<DomElementAttribute> &attributes,
                       const Vector<DomElement *> &children) : tag(tag), attributes(attributes), children(children) {}


DomElement::DomElement(std::istream &in) : tag(), attributes(), children() {
    //Skip all the leading whitespaces
    FileStreamHelper::skipWhitespaces(in);

    // Validate the element starts with an '<'
    if (in.get() != '<') {
        throw DomException(DomErrorCode::INVALID_DOM_ELEMENT_FORMAT);
    }

    // Get tag name
    Vector<char> tagDelimiters;
    tagDelimiters.push(' ');
    tagDelimiters.push('>');
    this->tag = String(in, tagDelimiters);
    FileStreamHelper::skipWhitespaces(in);

    // Get all attributes
    while (in.peek() != '/' && in.peek() != '>') {
        this->attributes.push(DomElementAttribute(in));
        FileStreamHelper::skipWhitespaces(in);
    }

    // Get children if the tag is not self-closing
    if (in.get() == '>') {
        // Skip spaces before children tags
        FileStreamHelper::skipWhitespaces(in);

        // Read children until closing tag
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

    //Skip all the whitespaces afterwards
    FileStreamHelper::skipWhitespaces(in);
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

std::ostream &operator<<(std::ostream &out, DomElement &domElement) {
    return domElement.serialize(out);
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

const Vector<DomElementAttribute> DomElement::getAttributes() const {
    return this->attributes;
}

void DomElement::setAttributes(const Vector<DomElementAttribute> &newAttributes) {
    this->attributes = newAttributes;
}

const Vector<DomElement *> &DomElement::getChildren() const {
    return this->children;
}

void DomElement::setChildren(const Vector<DomElement *> &newChildren) {
    for (unsigned int i = 0; i < this->children.getSize(); i++) {
        delete this->children[i];
    }

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

std::ostream &DomElement::serialize(std::ostream &out) {
    out << '<' << this->tag;

    for (unsigned int i = 0; i < this->attributes.getSize(); i++) {
        out << ' ' << this->attributes[i];
    }

    if (children.getSize() == 0) {
        out << "/>";
    } else {
        out << ">";
        for (unsigned int i = 0; i < this->children.getSize(); i++) {
            out << "\n\t" << *this->children[i];
        }

        out << "\n</" << this->tag << ">";
    }

    return out;
}
