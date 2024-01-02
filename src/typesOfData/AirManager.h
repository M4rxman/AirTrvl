#ifndef AIRMANAGER_H
#define AIRMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "position.h"

struct Airport {
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    Position position;
};

struct Airline {
    std::string code;
    std::string name;
    std::string callsign;
    std::string country;
};

class AirManager {
public:
    std::vector<Airport> airports;
    std::vector<Airline> airlines;

    bool readData() {
        if (!readAirports("airports.csv", airports)) {
            std::cerr << "Error reading airports data." << std::endl;
            return false;
        }

        if (!readAirlines("airlines.csv", airlines)) {
            std::cerr << "Error reading airlines data." << std::endl;
            return false;
        }

        // Data read successfully
        return true;
    }

private:
    bool readAirports(const std::string& filename, std::vector<Airport>& data) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return false;
        }

        data.clear(); // Clear the vector before reading

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Airport airport;

            if (std::getline(iss, airport.code, ',') &&
                std::getline(iss, airport.name, ',') &&
                std::getline(iss, airport.city, ',') &&
                std::getline(iss, airport.country, ',')) {

                // Convert latitude and longitude from string to double
                std::string latitudeStr, longitudeStr;
                if (std::getline(iss, latitudeStr, ',') &&
                    std::getline(iss, longitudeStr, ',')) {
                    airport.position.latitude = std::stod(latitudeStr);
                    airport.position.longitude = std::stod(longitudeStr);
                    data.push_back(airport);
                } else {
                    std::cerr << "Error parsing latitude and longitude in line: " << line << std::endl;
                }
            } else {
                std::cerr << "Error parsing line: " << line << std::endl;
            }
        }

        file.close();
        return true;
    }

    bool readAirlines(const std::string& filename, std::vector<Airline>& data) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return false;
        }

        data.clear(); // Clear the vector before reading

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Airline airline;

            if (std::getline(iss, airline.code, ',') &&
                std::getline(iss, airline.name, ',') &&
                std::getline(iss, airline.callsign, ',') &&
                std::getline(iss, airline.country, ',')) {
                data.push_back(airline);
            } else {
                std::cerr << "Error parsing line: " << line << std::endl;
            }
        }

        file.close();
        return true;
    }
};

#endif // AIRMANAGER_H
