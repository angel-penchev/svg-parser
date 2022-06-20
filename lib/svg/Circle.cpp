//
// Created by apenchev on 6/20/2022.
//

#include "../../include/svg/Circle.h"

Circle::Circle(const DomElement &domElement) : Shape(domElement) {
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

        if (domElement.getAttributes()[i].getName() == "cx") {
            this->cx = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "cy") {
            this->cy = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "r") {
            this->r = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }
    }
}

double Circle::getCx() const {
    return this->cx;
}

void Circle::setCx(double newCx) {
    this->cx = newCx;
}

double Circle::getCy() const {
    return this->cy;
}

void Circle::setCy(double newCy) {
    this->cy = newCy;
}

double Circle::getR() const {
    return this->r;
}

void Circle::setR(double newR) {
    this->r = newR;
}
