# this is only for a local test that uses main.cpp

cmake_minimum_required(VERSION 3.2)

project(go)

set(TARGET go)
set(SOURCES main.cpp debug_out.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${TARGET} ${SOURCES})
