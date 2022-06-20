//
// Created by apenchev on 6/20/2022.
//

#ifndef SVG_PARSER_RECT_H
#define SVG_PARSER_RECT_H


#include "Shape.h"

class Rect : public Shape {
private:
    double x = 0;
    double y = 0;
    double width = 0;
    double height = 0;
    double rx = 0;
    double ry = 0;
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

    DomElement toDomElement() override;
};


#endif //SVG_PARSER_RECT_H
