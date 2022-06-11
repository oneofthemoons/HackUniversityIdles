cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
project(tests)

set(SRC_LIST
    tests/parsing.cpp
)

add_executable(test ${SRC_LIST} tests/main.cpp)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR})