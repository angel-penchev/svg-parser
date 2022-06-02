//
// Created by apenchev on 5/30/2022.
//

#ifndef SVG_PARSER_STRING_H
#define SVG_PARSER_STRING_H


#include <ostream>

class String {
private:
    char *value = nullptr;

    void copy(const String &other);

    void clear();

public:
    String(const char *value = "");

    String(const String &other);

    String &operator=(const String &other);

    friend std::ostream &operator<<(std::ostream &out, const String &string);

    virtual ~String();

    const char *getValue() const;

    void setValue(const char *newValue);

    unsigned int getLength() const;
};


#endif //SVG_PARSER_STRING_H
