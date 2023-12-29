//
// Created by vikto on 12/21/2023.
//
#include "airports.h"
#include "csv-parser/csv.hpp"
#include <fstream>

std::vector<Airport> AirportDataReader::readAirportsFromFile(const std::string& filepath) {
    std::vector<Airport> airports;
    std::ifstream file(filepath);

    if (!file.is_open()) {
        // Handle file opening error
        return airports;
    }

    try {
        csv::CSVParser parser(file);
        for (auto& row : parser) {
            Airport airport;
            airport.code = row["Code"].get<std::string>();
            airport.name = row["Name"].get<std::string>();
            airport.city = row["City"].get<std::string>();
            airport.country = row["Country"].get<std::string>();
            airport.position.latitude = row["Latitude"].get<double>();
            airport.position.longitude = row["Longitude"].get<double>();

            airports.push_back(airport);
        }
    } catch (csv::Error& e) {
        // Handle CSV parsing error
    }

    return airports;
}
