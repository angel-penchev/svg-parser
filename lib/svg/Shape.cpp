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
