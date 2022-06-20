//
// Created by apenchev on 5/28/2022.
//

#ifndef SVG_PARSER_DOMDOCUMENT_H
#define SVG_PARSER_DOMDOCUMENT_H


#include "../helper/String.h"
#include "DomElement.h"

class DomDocument {
private:
    String versionTag;
    String doctypeTag;
    String filename;
    DomElement *parentElement = nullptr;

    void copy(const DomDocument &other);

    void clear();

public:
    DomDocument();

    explicit DomDocument(const String &filename);

    DomDocument(const DomDocument &other);

    DomDocument &operator=(const DomDocument &other);

    virtual ~DomDocument();

    void save();

    void saveAs(String &filepath);

    const String &getVersionTag() const;

    void setVersionTag(const String &newVersionTag);

    const String &getDoctypeTag() const;

    void setDoctypeTag(const String &newDoctypeTag);

    const String &getFilename() const;

    void setFilename(const String &newFilename);

    DomElement *getParentElement() const;

    void setParentElement(DomElement *newParentElement);

    std::ostream &serialize(std::ostream &out);
};


#endif //SVG_PARSER_DOMDOCUMENT_H
