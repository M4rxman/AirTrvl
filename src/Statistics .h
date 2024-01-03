
#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>

#include "typesOfData/AirTravelGraph.h" // Include your AirTravelGraph class here

class Statistics {
public:
    Statistics(const AirTravelGraph& airTravelGraph) : airTravelGraph(airTravelGraph) {}

    // Function to display global number of airports and flights
    void displayGlobalAirportsAndFlights() const {
        //std::cout << "Global number of airports: " << airTravelGraph.getGlobalAirportsCount() << std::endl;
        //std::cout << "Global number of flights: " << airTravelGraph.getGlobalFlightsCount() << std::endl;
    }

    // Add more statistical functions as needed

private:
    const AirTravelGraph& airTravelGraph;
};

#endif // STATISTICS_H