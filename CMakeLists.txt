cmake_minimum_required(VERSION 3.26)
project(AirTrvl C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src)

add_executable(AirTrvl
        src/Graph.h)
