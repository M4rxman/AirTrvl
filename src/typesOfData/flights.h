//
// Created by vikto on 12/28/2023.
//

#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <string>
#include <vector>
/**
* @brief Represents a flight between two locations operated by an airline.
*/
struct Flight { // this is our edge
    std::string source;     /**< Source airport or location code. */
    std::string target;     /**< Target airport or location code. */
    std::string airline;    /**< Airline operating the flight. */
};
/**
 * @brief Manages the collection of flight data.
 */
class FlightManager {
public:
    std::vector<Flight> flights; // Store flights data
    // Function to load flights from CSV file
    /**
* @brief Loads flight data from a CSV file.
* @param filename The name of the CSV file containing flight data.
* @return True if the data is loaded successfully, false otherwise.
*/
    bool loadFlights(const std::string& filename);
};

#endif


