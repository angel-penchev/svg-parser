//
// Created by apenchev on 6/20/2022.
//

#ifndef SVG_PARSER_SHAPE_H
#define SVG_PARSER_SHAPE_H


#include "../dom/DomElement.h"

class Shape {
protected:
    String fill;
    String stroke;
    unsigned int strokeWidth = 0;
public:
    explicit Shape(DomElement const &domElement = DomElement());

    const String &getFill() const;

    void setFill(const String &fill);

    const String &getStroke() const;

    void setStroke(const String &newStroke);

    unsigned int getStrokeWidth() const;

    void setStrokeWidth(unsigned int newStrokeWidth);

    virtual DomElement toDomElement();
};


#endif //SVG_PARSER_SHAPE_H
