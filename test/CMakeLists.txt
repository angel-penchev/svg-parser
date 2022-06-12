project(svg_parser_test)
include(FetchContent)
FetchContent_Declare(gtest
        QUIET
        URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
        )

# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

# add test source files
set(TEST_FILES
        e2e/SvgParserTest.cpp
        unit/dom/DomElementAttributeTest.cpp
        unit/dom/DomElementTest.cpp)

add_executable(svg_parser_test ${TEST_FILES})
target_link_libraries(svg_parser_test svg_parser_lib)
target_link_libraries(svg_parser_test gtest gtest_main)

# configure a constant path to fixtures folder
add_definitions("-DPATH_TO_FIXTURES=\"${CMAKE_SOURCE_DIR}/test/fixtures/\"")

# enable gtest discovery
include(GoogleTest)
gtest_discover_tests(svg_parser_test
        PROPERTIES
        DISCOVERY_TIMEOUT 240
        )