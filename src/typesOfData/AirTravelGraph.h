#include <unordered_map>
#include "graph.h"  // Include your Graph class here
#include "flights.h"  // Include your FlightManager class here
#include "position.h"  // Include your Position struct here
#include "AirManager.h"
/**
 * @brief Represents a graph for air travel connections.
 */

class AirTravelGraph {
private:
    Graph<std::string> graph;  // Assuming the vertex type is a string (airport code, airline code, or flight code)
/**< Graph containing airport, airline, and flight connections. */
public:
    /**
* @brief Adds airports to the graph.
* @param airports Vector containing Airport data.
*/
    // Function to add airports to the graph
    void addAirports(const std::vector<Airport>& airports) {
        for (const auto& airport : airports) {
            graph.addVertex(airport.code);
        }
    }
    /**
        * @brief Adds airlines to the graph.
        * @param airlines Vector containing Airline data.
        */
    // Function to add airlines to the graph
    void addAirlines(const std::vector<Airline>& airlines) {
        for (const auto& airline : airlines) {
            graph.addVertex(airline.code);
        }
    }
/**
     * @brief Adds flights to the graph.
     * @param flights Vector containing Flight data.
     */
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

    void setAdjacentVertices(const std::vector<Flight>& flights) {
        // Create a map to store the adjacent airports for each airport
        std::unordered_map<std::string, std::vector<std::string>> adjacentMap;

        // Iterate through flights and update the map
        for (const auto& flight : flights) {
            std::string sourceAirport = flight.source;
            std::string targetAirport = flight.target;
            std::string airline = flight.airline;

            // Check if the source airport is already in the map
            if (adjacentMap.find(sourceAirport) == adjacentMap.end()) {
                // If not, add it and initialize the vector
                adjacentMap[sourceAirport] = std::vector<std::string>();
            }
/*
            // Check if the target airport is not already in the vector
            if (std::find(adjacentMap[sourceAirport].begin(), adjacentMap[sourceAirport].end(), targetAirport) == adjacentMap[sourceAirport].end()) {
                // If not, add it to the vector
                adjacentMap[sourceAirport].push_back(targetAirport);
            }
        }

        // Set the adjacent vertices for each airport in the graph
        for (const auto& entry : adjacentMap) {
            const std::string& airport = entry.first;
            const std::vector<std::string>& adjacentAirports = entry.second;

            // Set the adjacent vertices for the airport in the graph
            graph.setAdjacentVertices(airport, adjacentAirports);
        */
        }
    }

    // Function to load data from CSV files and populate the graph
    // Constructor to initialize Statistics with the graph

    // Function to load data from CSV files and populate the graph
    /**
   * @brief Loads airport, airline, and flight data from CSV files and populates the graph.
   * @param airportsFile Filename for airports data in CSV format.
   * @param airlinesFile Filename for airlines data in CSV format.
   * @param flightsFile Filename for flights data in CSV format.
   * @return True if data is successfully loaded and graph is populated, false otherwise.
   */
    bool loadData(const std::string& airportsFile, const std::string& airlinesFile, const std::string& flightsFile) {
        AirManager airManager;

        if (!airManager.readData()) {
            return false;  // Error reading data
        }

        addAirports(airManager.airports);
        addAirlines(airManager.airlines);

        FlightManager flightManager;

        if (!flightManager.loadFlights(flightsFile)) {
            return false;  // Error loading flights data
        }

        addFlights(flightManager.flights);


        return true;
    }

    // Other functions related to the graph can be added here
};
