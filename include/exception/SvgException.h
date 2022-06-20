//
// Created by apenchev on 6/20/2022.
//

#ifndef SVG_PARSER_SVGEXCEPTION_H
#define SVG_PARSER_SVGEXCEPTION_H

#include "SvgErrorCode.h"
#include "Exception.h"

class SvgException : public Exception<SvgErrorCode> {
public:
    explicit SvgException(SvgErrorCode errorCode);

    const char *getErrorMessage() const override;
};


#endif //SVG_PARSER_SVGEXCEPTION_H
