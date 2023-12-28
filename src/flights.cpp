//
// Created by vikto on 12/28/2023.
//
#include "flights.h"
#include <fstream>
#include <sstream>

bool FlightManager::loadFlights(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false; // File not opened
    }

    // Clear existing flights if needed
    flights.clear();

    std::string line;
    std::getline(file, line); // Read and discard header

    while (std::getline(file, line)) {
        std::istringstream linestream(line);
        std::string source, target, airline;

        if (std::getline(linestream, source, ',') &&
            std::getline(linestream, target, ',') &&
            std::getline(linestream, airline, ',')) {
            // Create a Flight object and add it to flights vector
            flights.push_back({source, target, airline});
        } else {
            // Error in line format
            return false;
        }
    }

    file.close();
    return true;
}
