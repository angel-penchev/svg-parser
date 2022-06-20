//
// Created by apenchev on 6/20/2022.
//

#ifndef SVG_PARSER_SHAPE_H
#define SVG_PARSER_SHAPE_H


#include "../dom/DomElement.h"

class Shape {
private:
    String fill;
    String stroke;
    unsigned int strokeWidth;
public:
    explicit Shape(DomElement const &domElement = DomElement());
};


#endif //SVG_PARSER_SHAPE_H
