//
// Created by apenchev on 6/20/2022.
//

#ifndef SVG_PARSER_SVG_H
#define SVG_PARSER_SVG_H


#include "../helper/Vector.h"
#include "Shape.h"
#include "../dom/DomDocument.h"

class Svg {
private:
    DomDocument document;
    Vector<Shape> shapes;
public:
    explicit Svg(const DomDocument &document);

    const DomDocument &getDocument() const;

    void setDocument(const DomDocument &newDocument);

    const Vector<Shape> &getShapes() const;

    void setShapes(const Vector<Shape> &newShapes);

    void updateDocument();
};


#endif //SVG_PARSER_SVG_H
