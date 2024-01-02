cmake_minimum_required(VERSION 3.26)
project(AirTrvl)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src)
include_directories(data)

add_executable(AirTrvl
        src/typesOfData/Graph.h
        src/typesOfData/AirManager.h
        src/typesOfData/flights.h
        src/typesOfData/flights.cpp
        src/csv.hpp
        csv-parser-master/csv-parser-master/single_include/csv.hpp
)
