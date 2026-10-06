cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_FLAGS "-Wall -std=c23")

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall -std=c++26")

project(narytree VERSION 1.0)
add_executable(main main.c narytree.c)
