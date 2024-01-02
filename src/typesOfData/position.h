//
// Created by alex2 on 27.12.2023.
//

#ifndef AIRTRVL_POSITION_H
#define AIRTRVL_POSITION_H

#include <cmath>
#include <iostream>

struct Position {
    double latitude;
    double longitude;

    // Default constructor
    Position() : latitude(0.0), longitude(0.0) {}

    // Parameterized constructor
    Position(double lat, double lon) : latitude(lat), longitude(lon) {}

    // Function to calculate the distance between two positions using Haversine formula
    double distance(const Position& other) const {
        const double R = 6371.0;  // Earth radius in kilometers

        double dLat = deg2rad(other.latitude - latitude);
        double dLon = deg2rad(other.longitude - longitude);

        double a = sin(dLat / 2.0) * sin(dLat / 2.0) +
                   cos(deg2rad(latitude)) * cos(deg2rad(other.latitude)) *
                   sin(dLon / 2.0) * sin(dLon / 2.0);

        double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

        return R * c;  // Distance in kilometers
    }

    // Function to convert degrees to radians
    double deg2rad(double deg) const {
        return deg * (M_PI / 180.0);
    }

};



#endif //AIRTRVL_POSITION_H
