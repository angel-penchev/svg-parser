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
    DomElement *child = nullptr;

    void copy(const DomElement &other);

    void clear();

public:
    explicit DomElement(const String &tag = "",
                        const Vector<DomElementAttribute> &attributes = Vector<DomElementAttribute>(),
                        DomElement *child = nullptr);

    DomElement(const DomElement &other);

    explicit DomElement(std::istream &in);

    DomElement &operator=(const DomElement &other);

    virtual ~DomElement();

    const String &getTag() const;

    void setTag(const String &tag);

    const Vector<DomElementAttribute> &getAttributes() const;

    void setAttributes(const Vector<DomElementAttribute> &newAttributes);

    DomElement *getChild() const;

    void setChild(const DomElement *newChild);
};


#endif //SVG_PARSER_DOMELEMENT_H
