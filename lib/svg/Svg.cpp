//
// Created by apenchev on 6/20/2022.
//

#include "../../include/svg/Svg.h"
#include "../../include/svg/Rect.h"
#include "../../include/svg/Circle.h"
#include "../../include/exception/SvgException.h"

Svg::Svg() : document(), shapes() {}

/**
 * Svg constructor from DomDocument.
 * @param document DomDocument to be read
 */
Svg::Svg(const DomDocument &document) : document(document), shapes() {
    // Validate xml version tag
    if (this->document.getVersionTag() != R"(<?xml version="1.0" standalone="no"?>)") {
        throw SvgException(SvgErrorCode::INVALID_XML_VERSION_TAG);
    }

    // Validate dom doctype
    if (this->document.getDoctypeTag() !=
        R"(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)") {
        throw SvgException(SvgErrorCode::INVALID_DOCTYPE_TAG);
    }

    // Validate that the parent node is a svg
    if (this->document.getParentElement()->getTag() != "svg") {
        throw SvgException(SvgErrorCode::INVALID_PARENT_ELEMENT_TAG);
    }

    // Validate parent XML namespace
    if (!this->document.getParentElement()->getAttributes().contains(
            DomElementAttribute("xmlns", "http://www.w3.org/2000/svg"))) {
        throw SvgException(SvgErrorCode::INVALID_PARENT_ELEMENT_XMLNS);
    }

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

/**
 * DomDocument getter.
 * @return SVG DomDocument
 */
DomDocument Svg::getDocument() const {
    return document;
}

/**
 * DomDocument setter.
 * @param newDocument DomDocument to be set.
 */
void Svg::setDocument(const DomDocument &newDocument) {
    this->document = newDocument;
}

/**
 * Shapes getter.
 * @return SVG shapes.
 */
const Vector<Shape> &Svg::getShapes() const {
    return this->shapes;
}

/**
 * Shapes setter.
 * @param newShapes SVG shapes to be set
 */
void Svg::setShapes(const Vector<Shape> &newShapes) {
    this->shapes = newShapes;
}

/**
 * Updates the SVG document with information from shapes.
 */
void Svg::updateDocument() {
    Vector<DomElement *> updatedChildren;
    for (unsigned int i = 0; i < this->shapes.getSize(); i++) {
        updatedChildren.push(new DomElement(this->shapes[i].toDomElement()));
    }
    this->document.getParentElement()->setChildren(updatedChildren);
}
