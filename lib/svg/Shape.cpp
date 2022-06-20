//
// Created by apenchev on 6/20/2022.
//

#include "../../include/svg/Shape.h"

Shape::Shape(DomElement const &domElement) : fill(), stroke(), strokeWidth() {
    for (unsigned int i = 0; i < domElement.getAttributes().getSize(); i++) {
        if (domElement.getAttributes()[i].getName() == "fill") {
            this->fill = domElement.getAttributes()[i].getValue();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "stroke") {
            this->stroke = domElement.getAttributes()[i].getValue();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "stroke-width") {
            this->strokeWidth = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }
    }
}

const String &Shape::getFill() const {
    return this->fill;
}

void Shape::setFill(const String &newFill) {
    this->fill = newFill;
}

const String &Shape::getStroke() const {
    return this->stroke;
}

void Shape::setStroke(const String &newStroke) {
    this->stroke = newStroke;
}

unsigned int Shape::getStrokeWidth() const {
    return this->strokeWidth;
}

void Shape::setStrokeWidth(unsigned int newStrokeWidth) {
    this->strokeWidth = newStrokeWidth;
}
