//
// Created by apenchev on 6/20/2022.
//

#ifndef SVG_PARSER_RECT_H
#define SVG_PARSER_RECT_H


#include "Shape.h"

class Rect : public Shape {
private:
    double x;
    double y;
    double width;
    double height;
    double rx;
    double ry;
public:
    explicit Rect(DomElement const &domElement = DomElement());

    double getX() const;

    void setX(double newX);

    double getY() const;

    void setY(double y);

    double getWidth() const;

    void setWidth(double newWidth);

    double getHeight() const;

    void setHeight(double newHeight);

    double getRx() const;

    void setRx(double newRx);

    double getRy() const;

    void setRy(double newRy);
};


#endif //SVG_PARSER_RECT_H
