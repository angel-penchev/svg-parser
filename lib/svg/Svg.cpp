//
// Created by apenchev on 6/20/2022.
//

#include "../../include/svg/Svg.h"
#include "../../include/svg/Rect.h"
#include "../../include/svg/Circle.h"
#include "../../include/exception/SvgException.h"

Svg::Svg(const DomDocument &document) : document(document), shapes() {
    // Validate xml version tag
    if (this->document.getVersionTag() != R"(<?xml version="1.0" standalone="no"?>)") {
        throw SvgException(SvgErrorCode::INVALID_XML_VERSION_TAG);
    }

    // Validate dom doctype
    if (this->document.getVersionTag() !=
        R"(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)") {
        throw SvgException(SvgErrorCode::INVALID_DOCTYPE_TAG);
    }

    // Validate that the parent node is a svg
    if (this->document.getParentElement()->getTag() == "svg") {
        throw SvgException(SvgErrorCode::INVALID_PARENT_ELEMENT_TAG);
    }

    // TODO: xmlns validation

    // Convert elements into shapes
    for (unsigned int i = 0; document.getParentElement()->getChildren().getSize() < i; i++) {
        if (document.getParentElement()->getChildren()[i]->getTag() == "rect") {
            this->shapes.push(Rect(*document.getParentElement()->getChildren()[i]));
        }

        if (document.getParentElement()->getChildren()[i]->getTag() == "circle") {
            this->shapes.push(Circle(*document.getParentElement()->getChildren()[i]));
        }
    }
}

const DomDocument &Svg::getDocument() const {
    return document;
}

void Svg::setDocument(const DomDocument &newDocument) {
    this->document = newDocument;
}

const Vector<Shape> &Svg::getShapes() const {
    return this->shapes;
}

void Svg::setShapes(const Vector<Shape> &newShapes) {
    this->shapes = newShapes;
}

void Svg::updateDocument() {
    Vector<DomElement *> updatedChildren;
    for (unsigned int i = 0; i < this->shapes.getSize(); i++) {
        updatedChildren.push(new DomElement(this->shapes[i].toDomElement()));
    }
    this->document.getParentElement()->setChildren(updatedChildren);
}
