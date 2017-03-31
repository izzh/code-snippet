cmake_minimum_required(VERSION 2.6)

project(algorithms)

set(PROJECT_MAJOR_VERSION 1)
set(PROJECT_MINOR_VERSION 0)
set(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION})

set(CXX_FLAGS
 -g
 -Wall
 -Wextra
 -Werror
 -Wno-unused-parameter
 -std=c++11
)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++")

add_subdirectory(sort)

message("this is algorithms cpp code")
