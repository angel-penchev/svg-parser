//
// Created by apenchev on 5/30/2022.
//

#ifndef SVG_PARSER_HELPEREXCEPTION_H
#define SVG_PARSER_HELPEREXCEPTION_H


#include "HelperErrorCode.h"
#include "Exception.h"

class HelperException : public Exception<HelperErrorCode> {
public:
    explicit HelperException(HelperErrorCode errorCode);

    const char *getErrorMessage() const override;
};


#endif //SVG_PARSER_HELPEREXCEPTION_H
