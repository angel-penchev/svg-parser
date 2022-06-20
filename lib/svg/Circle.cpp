//
// Created by apenchev on 6/20/2022.
//

#include "../../include/svg/Circle.h"

/**
 * Circle constructor from DomElement.
 * @param domElement DomElement to be read.
 */
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

/**
 * Circle center X (cx) getter.
 * @return Circle cx
 */
double Circle::getCx() const {
    return this->cx;
}

/**
 * Circle center X (cx) setter.
 * @return Circle cx to be set
 */
void Circle::setCx(double newCx) {
    this->cx = newCx;
}

/**
 * Circle center Y (cy) getter.
 * @return Circle cy
 */
double Circle::getCy() const {
    return this->cy;
}

/**
 * Circle center Y (cy) setter.
 * @return Circle cy to be set
 */
void Circle::setCy(double newCy) {
    this->cy = newCy;
}

/**
 * Circle radius (r) getter.
 * @return Circle r.
 */
double Circle::getR() const {
    return this->r;
}

/**
 * Circle radius (r) setter.
 * @return Circle r to be set
 */
void Circle::setR(double newR) {
    this->r = newR;
}

DomElement Circle::toDomElement() {
    DomElement result = Shape::toDomElement();

    Vector<DomElementAttribute> attributes = result.getAttributes();
    attributes.push(DomElementAttribute("cx", cx));
    attributes.push(DomElementAttribute("cy", cy));
    attributes.push(DomElementAttribute("r", r));

    result.setTag("circle");
    result.setAttributes(attributes);

    return result;
}
