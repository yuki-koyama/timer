cmake_minimum_required(VERSION 3.1)

project(timer CXX)
set(CMAKE_CXX_STANDARD 11)

file(GLOB headers timer/*.hpp)
install(FILES ${headers} DESTINATION include/timer)

