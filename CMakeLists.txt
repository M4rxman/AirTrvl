cmake_minimum_required(VERSION 3.26)
project(AirTrvl)

set(CSV_CXX_STANDARD 11)

include_directories(src)
include_directories(data)

add_executable(AirTrvl
        src/typesOfData/Graph.h
        src/typesOfData/AirManager.h
        src/typesOfData/flights.h
        src/typesOfData/flights.cpp
        src/typesOfData/AirTravelGraph.h
)
