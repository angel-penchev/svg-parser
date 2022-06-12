//
// Created by apenchev on 5/28/2022.
//

#ifndef SVG_PARSER_DOMELEMENT_H
#define SVG_PARSER_DOMELEMENT_H


#include <iostream>
#include "DomElementAttribute.h"
#include "../helper/Vector.h"

class DomElement {
private:
    String tag;
    Vector<DomElementAttribute> attributes;
    Vector<DomElement *> children;

    void copy(const DomElement &other);

    void clear();

public:
    explicit DomElement(const String &tag = "",
                        const Vector<DomElementAttribute> &attributes = Vector<DomElementAttribute>(),
                        const Vector<DomElement *> &children = Vector<DomElement *>());

    explicit DomElement(std::istream &in);

    DomElement(const DomElement &other);

    DomElement &operator=(const DomElement &other);

    virtual ~DomElement();

    const String &getTag() const;

    void setTag(const String &tag);

    const Vector<DomElementAttribute> &getAttributes() const;

    void setAttributes(const Vector<DomElementAttribute> &newAttributes);

    const Vector<DomElement *> &getChildren() const;

    void setChildren(const Vector<DomElement *> &newChildren);
};


#endif //SVG_PARSER_DOMELEMENT_H
