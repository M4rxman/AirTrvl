#include <iostream>
#include "typesOfData/AirTravelGraph.h"


void displayAirportInformation(const AirManager& airManager) {
    // Display airport information
    std::cout << "===== Airport Information =====\n";
    for (const auto& airport : airManager.airports) {
        std::cout << "Code: " << airport.code << "\n"
                  << "Name: " << airport.name << "\n"
                  << "City: " << airport.city << "\n"
                  << "Country: " << airport.country << "\n"
                  << "Latitude: " << airport.position.str_latitude << "\n"
                  << "Longitude: " << airport.position.str_longitude << "\n\n";
    }
}

// Implement similar functions for displaying airline and flight information
/**
 * @brief The main function for initializing and loading data into the AirTravelGraph.
 *
 * This function creates an instance of AirTravelGraph, loads data from CSV files
 * ('airports.csv', 'airlines.csv', 'flights.csv') into the graph, and handles errors if any occur.
 *
 * @return An integer representing the exit status:
 *         - 0 if the data is successfully loaded.
 *         - 1 if an error occurs while loading data from CSV files.
 */

int main() {
    AirManager airManager;
    FlightManager flightManager;
    AirTravelGraph airTravelGraph;

    // Load data from CSV files
    if (!airManager.readData()) {
        std::cerr << "Error loading airport and airline data." << std::endl;
        return 1;
    }


    // Populate the graph with data
    airTravelGraph.addAirports(airManager.airports);
    airTravelGraph.addAirlines(airManager.airlines);
    airTravelGraph.addFlights(flightManager.flights);

    int choice;

    do {
        // Display menu
        std::cout << "===== Flight Management System =====\n"
                  << "1. Display Airport Information\n"
                  << "2. Display Airline Information\n"
                  << "3. Display Flight Information\n"
                  << "4. Search for Flights\n"
                  << "5. Show Global Connectivity\n"
                  << "6. Exit\n"
                  << "====================================\n"
                  << "Enter your choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                displayAirportInformation(airManager);
                break;
                // Implement cases for other menu options

            case 6:
                std::cout << "Exiting the Flight Management System. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}
