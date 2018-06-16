cmake_minimum_required(VERSION 3.1)

project(timer CXX)
set(CMAKE_CXX_STANDARD 11)

file(GLOB header timer.hpp)
install(FILES ${header} DESTINATION include)

