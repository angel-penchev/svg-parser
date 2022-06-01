set(LIBRARY_NAME svg_parser_lib)

project(${LIBRARY_NAME})

set(HEADERS_DIR ../include)

set(HEADER_FILES
        ${HEADERS_DIR}/exception/Exception.h
        ${HEADERS_DIR}/exception/HelperException.h
        ${HEADERS_DIR}/exception/HelperErrorCode.h
        ${HEADERS_DIR}/helper/String.h)

set(SOURCE_FILES
        exception/HelperException.cpp
        helper/String.cpp)

add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
