//
// Created by apenchev on 5/30/2022.
//

#ifndef SVG_PARSER_STRING_H
#define SVG_PARSER_STRING_H


#include <ostream>

#define MAX_STRING_LEN 1024

class String {
private:
    char *value = nullptr;

    void copy(const String &other);

    void clear();

public:
    String(const char *value = "");

    String(const String &other);

    String(std::istream &in, char delimiter);

    String &operator=(const String &other);

    friend std::ostream &operator<<(std::ostream &out, const String &string);

    String operator+(const String &other) const;

    bool operator==(const String &other) const;

    bool operator!=(const String &rhs) const;

    virtual ~String();

    const char *getValue() const;

    void setValue(const char *newValue);

    unsigned int getLength() const;

    String concatenate(const String &other) const;
};


#endif //SVG_PARSER_STRING_H
