set(LIBRARY_NAME svg_parser_lib)

project(${LIBRARY_NAME})

set(HEADERS_DIR ../include)

set(HEADER_FILES
        ${HEADERS_DIR}/exception/Exception.h
        ${HEADERS_DIR}/exception/HelperException.h
        ${HEADERS_DIR}/exception/HelperErrorCode.h
        ${HEADERS_DIR}/exception/DomException.h
        ${HEADERS_DIR}/exception/DomErrorCode.h
        ${HEADERS_DIR}/helper/String.h
        ${HEADERS_DIR}/helper/Vector.h
        ${HEADERS_DIR}/helper/FileStreamHelper.h
        ${HEADERS_DIR}/dom/DomDocument.h
        ${HEADERS_DIR}/dom/DomElement.h
        ${HEADERS_DIR}/dom/DomElementAttribute.h
        ${HEADERS_DIR}/program/Program.h)

set(SOURCE_FILES
        exception/HelperException.cpp
        exception/DomException.cpp
        helper/String.cpp
        helper/FileStreamHelper.cpp
        dom/DomDocument.cpp
        dom/DomElement.cpp
        dom/DomElementAttribute.cpp
        program/Program.cpp)

add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
