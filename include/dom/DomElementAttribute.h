//
// Created by apenchev on 5/28/2022.
//

#ifndef SVG_PARSER_DOMELEMENTATTRIBUTE_H
#define SVG_PARSER_DOMELEMENTATTRIBUTE_H


#include <fstream>
#include "../helper/String.h"
#include "../../include/exception/DomException.h"

class DomElementAttribute {
private:
    String name;
    String value;
public:
    explicit DomElementAttribute(const String &name = "", const String &value = "");

    explicit DomElementAttribute(std::istream &in);

    String getName() const;

    void setName(const String &newName);

    String getValue() const;

    void setValue(const String &newValue);
};


#endif //SVG_PARSER_DOMELEMENTATTRIBUTE_H
