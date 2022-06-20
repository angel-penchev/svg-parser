//
// Created by apenchev on 5/28/2022.
//

#ifndef SVG_PARSER_DOMDOCUMENT_H
#define SVG_PARSER_DOMDOCUMENT_H


#include "../helper/String.h"
#include "DomElement.h"

class DomDocument {
private:
    String filename;
    Vector<DomElement *> elements;

    void copy(const DomDocument &other);

    void clear();

public:
    explicit DomDocument(const String &filename);

    DomDocument(const DomDocument &other);

    DomDocument &operator=(const DomDocument &other);

    virtual ~DomDocument();

    void serialize(std::ostream out);

    const String &getFilename() const;

    void setFilename(const String &newFilename);

    const Vector<DomElement *> &getElements() const;

    void setElements(const Vector<DomElement *> &newElements);
};


#endif //SVG_PARSER_DOMDOCUMENT_H
