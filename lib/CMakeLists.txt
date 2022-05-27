set(LIBRARY_NAME svg_parser_lib)

project(${LIBRARY_NAME})

set(HEADERS_DIR ../include)

set(HEADER_FILES
        ${HEADERS_DIR}/program/Program.h)

set(SOURCE_FILES
        program/Program.cpp)

add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
