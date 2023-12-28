//
// Created by vikto on 12/28/2023.
//

#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <string>
#include <vector>

struct Flight {
    std::string source;
    std::string target;
    std::string airline;
};

class FlightManager {
public:
    std::vector<Flight> flights; // Store flights data

    // Function to load flights from CSV file
    bool loadFlights(const std::string& filename);
};

#endif


