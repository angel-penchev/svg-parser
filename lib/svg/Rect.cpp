//
// Created by apenchev on 6/20/2022.
//

#include "../../include/svg/Rect.h"

Rect::Rect(DomElement const &domElement) : Shape(), x(), y(), width(), height(), rx(), ry() {
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
        
        if (domElement.getAttributes()[i].getName() == "x") {
            this->x = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "y") {
            this->y = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "width") {
            this->width = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "height") {
            this->height = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "rx") {
            this->rx = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }

        if (domElement.getAttributes()[i].getName() == "ry") {
            this->ry = domElement.getAttributes()[i].getValue().toDouble();
            continue;
        }
    }
}

double Rect::getX() const {
    return this->x;
}

void Rect::setX(double newX) {
    this->x = newX;
}

double Rect::getY() const {
    return this->y;
}

void Rect::setY(double y) {
    this->y = y;
}

double Rect::getWidth() const {
    return this->width;
}

void Rect::setWidth(double newWidth) {
    this->width = newWidth;
}

double Rect::getHeight() const {
    return this->height;
}

void Rect::setHeight(double newHeight) {
    this->height = newHeight;
}

double Rect::getRx() const {
    return this->rx;
}

void Rect::setRx(double newRx) {
    this->rx = newRx;
}

double Rect::getRy() const {
    return ry;
}

void Rect::setRy(double newRy) {
    Rect::ry = newRy;
}
