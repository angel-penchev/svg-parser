//
// Created by apenchev on 6/20/2022.
//

#include <stdexcept>
#include "../../include/exception/SvgException.h"

SvgException::SvgException(SvgErrorCode errorCode) : Exception(errorCode) {}

const char *SvgException::getErrorMessage() const {
    switch (this->errorCode) {
        case SvgErrorCode::INVALID_XML_VERSION_TAG:
            return "Invalid XML version tag.";
        case SvgErrorCode::INVALID_DOCTYPE_TAG:
            return "Invalid DOCTYPE tag.";
        case SvgErrorCode::INVALID_PARENT_ELEMENT_TAG:
            return "Invalid parent node tag.";
        default:
            throw std::invalid_argument("Unimplemented item.");
    }
}
