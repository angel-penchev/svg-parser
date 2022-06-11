//
// Created by apenchev on 6/2/2022.
//

#include "../../include/exception/DomException.h"

DomException::DomException(DomErrorCode errorCode) : Exception(errorCode) {}

const char *DomException::getErrorMessage() const {
    switch (this->errorCode) {
        case DomErrorCode::CANNOT_SET_NULLPTR_AS_DOM_VALUE:
            return "Cannot assign value from null pointer.";
        case DomErrorCode::INVALID_DOM_ELEMENT_FORMAT:
            return "Invalid DOM element formatting.";
        case DomErrorCode::INVALID_DOM_ATTRIBUTE_FORMAT:
            return "Invalid DOM attribute formatting.";
        default:
            throw std::invalid_argument("Unimplemented item.");
    }
}

