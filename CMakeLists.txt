cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILE main.cpp)
set(PROJECT_NAME svg_parser)
set(LIBRARY svg_parser_lib)


project(
        ${PROJECT_NAME}
        VERSION 1.0
        DESCRIPTION "Command-line software solution for processing scalable graphic files (SVGs)."
        LANGUAGES CXX)

# Testing
enable_testing()
add_subdirectory(test)

# Project
add_executable(${PROJECT_NAME} ${SOURCE_FILE})

add_subdirectory(lib)
include_directories(include)

target_link_libraries(${PROJECT_NAME} ${LIBRARY})
