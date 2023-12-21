//
// Created by vikto on 12/21/2023.
//

#ifndef AIRTRVL_AIRPORTS_H
#define AIRTRVL_AIRPORTS_H

#include<string>
#include<vector>

struct Airport {
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    double latitude;
    double longitude;
};
class AirportDataReader {
public:
    std::vector<Airport> readAirportsFromFile(const std::string& filepath);
};

#endif //AIRTRVL_AIRPORTS_H

