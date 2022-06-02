//
// Created by apenchev on 6/2/2022.
//

#ifndef SVG_PARSER_DOMEXCEPTION_H
#define SVG_PARSER_DOMEXCEPTION_H


#include <stdexcept>
#include "DomErrorCode.h"
#include "Exception.h"

class DomException : public Exception<DomErrorCode> {
public:
    explicit DomException(DomErrorCode errorCode);

    const char *getErrorMessage() const override;
};


#endif //SVG_PARSER_DOMEXCEPTION_H
