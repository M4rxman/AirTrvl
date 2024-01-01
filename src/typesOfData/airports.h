//
// Created by vikto on 12/21/2023.
//

#ifndef AIRTRVL_AIRPORTS_H
#define AIRTRVL_AIRPORTS_H

#include<string>
#include<vector>
#include "position.h"

struct Airport {
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    Position position;  
};
class AirportDataReader {
    std::vector<Airport> _airpots;
public:
    std::vector<Airport> readAirportsFromFile(const std::string& filepath);
};

#endif //AIRTRVL_AIRPORTS_H

