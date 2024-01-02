#include "typesOfData/AirTravelGraph.h"

using namespace std;

int main() {
    AirTravelGraph airTravelGraph;
    if (!airTravelGraph.loadData("airports.csv", "airlines.csv", "flights.csv")) {
        std::cerr << "Error loading data from CSV files." << std::endl;
        return 1;
    }

    // Now you have the graph populated with data from the CSV files

    return 0;
}
