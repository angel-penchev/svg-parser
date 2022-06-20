//
// Created by apenchev on 6/20/2022.
//

#ifndef SVG_PARSER_CIRCLE_H
#define SVG_PARSER_CIRCLE_H


#include "Shape.h"

class Circle : public Shape {
private:
    double cx;
    double cy;
    double r;
public:
    explicit Circle(DomElement const &domElement = DomElement());

    double getCx() const;

    void setCx(double newCx);

    double getCy() const;

    void setCy(double newCy);

    double getR() const;

    void setR(double newR);
};


#endif //SVG_PARSER_CIRCLE_H
