//
// Created by apenchev on 5/28/2022.
//

#ifndef SVG_PARSER_DOMELEMENTATTRIBUTE_H
#define SVG_PARSER_DOMELEMENTATTRIBUTE_H


#include "../helper/String.h"

class DomElementAttribute {
private:
    String name;
    String value;
public:
    explicit DomElementAttribute(const String &name = "", const String &value = "");

    String getName() const;

    void setName(const String &newName);

    String getValue() const;

    void setValue(const String &newValue);
};


#endif //SVG_PARSER_DOMELEMENTATTRIBUTE_H
