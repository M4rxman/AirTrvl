//
// Created by vikto on 12/28/2023.
//
#include "flights.h"
#include <fstream>
#include <sstream>
#include <iostream>
/**
 * @brief Loads flight data from a CSV file into the FlightManager.
 *
 * Reads flight data from a CSV file with the format: source,target,airline.
 *
 * @param filename The name of the CSV file containing flight data.
 * @return True if the data is loaded successfully, false otherwise (including file not found or incorrect format).
 */
bool FlightManager::loadFlights(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }

    flights.clear(); // Clear the vector before reading

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Flight flight;

        if (std::getline(iss, flight.source, ',') &&
            std::getline(iss, flight.target, ',') &&
            std::getline(iss, flight.airline, ',')) {
            flights.push_back(flight);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    file.close();
    return true;
}