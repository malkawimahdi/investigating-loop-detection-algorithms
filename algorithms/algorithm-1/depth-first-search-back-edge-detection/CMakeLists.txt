#[[Please modify project(NAME_OF_PROJECT)]]#
#[[Please modify the first argument of add_executable(NAME_OF_PROJECT main.cpp Graph.cpp Graph.h]]#
cmake_minimum_required(VERSION 3.24)
project(Algorithm1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithm1 main.cpp Graph.cpp Graph.h)
