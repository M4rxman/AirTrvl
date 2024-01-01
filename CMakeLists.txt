cmake_minimum_required(VERSION 3.26)
project(AirTrvl)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src)
include_directories(data)

add_executable(AirTrvl
        src/typesOfData/Graph.h
        src/typesOfData/airports.cpp
        src/typesOfData/airports.h
        src/flights.h
        src/flights.cpp
)
