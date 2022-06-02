//
// Created by apenchev on 5/30/2022.
//

#include <stdexcept>
#include "../../include/exception/HelperException.h"

HelperException::HelperException(HelperErrorCode errorCode) : Exception(errorCode) {}

const char *HelperException::getErrorMessage() const {
    switch (this->errorCode) {
        case HelperErrorCode::CANNOT_SET_NULLPTR_AS_HELPER_VALUE:
            return "Cannot assign value from null pointer.";
        case HelperErrorCode::INDEX_OUT_OF_INDEX:
            return "Index specified is out of the array range.";
        default:
            throw std::invalid_argument("Unimplemented item.");
    }
}

