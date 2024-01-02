#include <iostream>
#include <vector>
#include "position.h"
#include "csv-parser-master/csv-parser-master/single_include/csv.hpp"



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

int main() {
    std::vector<Airport> airports;
    csv::CSVReader<csv::N_COLUMNS> airportCSV("airports.csv");
    airports.reserve(1000); // Set an appropriate initial capacity

    Airport airport;
    for (auto& row : airportCSV) {
        airport.code = row["Code"].get<std::string>();
        airport.name = row["Name"].get<std::string>();
        airport.city = row["City"].get<std::string>();
        airport.country = row["Country"].get<std::string>();
        airport.position.latitude = row["Latitude"].get<double>();
        airport.position.longitude = row["Longitude"].get<double>();
        airports.push_back(airport);
    }

    std::vector<Airline> airlines;
    csv::CSVReader<csv::N_COLUMNS> airlineCSV("airlines.csv");
    airlines.reserve(1000); // Set an appropriate initial capacity

    Airline airline;
    for (auto& row : airlineCSV) {
        airline.code = row["Code"].get<std::string>();
        airline.name = row["Name"].get<std::string>();
        airline.callsign = row["Callsign"].get<std::string>();
        airline.country = row["Country"].get<std::string>();
        airlines.push_back(airline);
    }

    // Now you have vectors 'airports' and 'airlines' filled with your CSV data
    return 0;
}
