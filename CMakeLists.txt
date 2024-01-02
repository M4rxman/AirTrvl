cmake_minimum_required(VERSION 3.26)
project(AirTrvl)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(data)

add_executable(AirTrvl
        src/typesOfData/Graph.h
        src/typesOfData/AirManager.h
        src/typesOfData/flights.h
        src/typesOfData/flights.cpp
        src/csv.hpp
        src/typesOfData/AirTravelGraph.h
)
