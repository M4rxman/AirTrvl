#include "graph.h"  // Include your Graph class here
#include "flights.h"  // Include your FlightManager class here
#include "position.h"  // Include your Position struct here
#include "AirManager.h"

class AirTravelGraph {
private:
    Graph<std::string> graph;  // Assuming the vertex type is a string (airport code, airline code, or flight code)

public:
    // Function to add airports to the graph
    void addAirports(const std::vector<Airport>& airports) {
        for (const auto& airport : airports) {
            graph.addVertex(airport.code);
        }
    }

    // Function to add airlines to the graph
    void addAirlines(const std::vector<Airline>& airlines) {
        for (const auto& airline : airlines) {
            graph.addVertex(airline.code);
        }
    }

    // Function to add flights to the graph
    void addFlights(const std::vector<Flight>& flights) {
        for (const auto& flight : flights) {
            std::string flightCode = flight.source + "-" + flight.target + "-" + flight.airline;
            graph.addVertex(flightCode);

            // Connect the flight to the corresponding airport and airline
            graph.addEdge(flightCode, flight.source, 1);  // Assuming a weight of 1 for simplicity
            graph.addEdge(flightCode, flight.target, 1);  // Assuming a weight of 1 for simplicity
            graph.addEdge(flightCode, flight.airline, 1);  // Assuming a weight of 1 for simplicity
        }
    }

    // Function to load data from CSV files and populate the graph
    bool loadData(const std::string& airportsFile, const std::string& airlinesFile, const std::string& flightsFile) {
        FlightManager flightManager;
        AirManager airManager;

        if (!flightManager.loadFlights(flightsFile)) {
            return false;  // Error loading flights data
        }

        addAirports(airManager.airports);
        addAirlines(airManager.airlines);
        addFlights(flightManager.flights);

        return true;
    }

    // Other functions related to the graph can be added here
};

