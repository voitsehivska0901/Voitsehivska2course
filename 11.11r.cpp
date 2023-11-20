#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


struct Passenger {
    int number;
    std::string name;
};

struct Baggage {
    int passengerNumber;
    int numItems;
    double weight;
};


bool haveSimilarBags(const std::vector<Passenger>& passengers, const std::vector<Baggage>& baggage, double maxWeightDifference) {
    for (size_t i = 0; i < passengers.size() - 1; ++i) {
        for (size_t j = i + 1; j < passengers.size(); ++j) {
            // Check if both passengers have baggage
            auto baggageItr1 = std::find_if(baggage.begin(), baggage.end(), [&passengers, i](const Baggage& b) {
                return b.passengerNumber == passengers[i].number;
                });

            auto baggageItr2 = std::find_if(baggage.begin(), baggage.end(), [&passengers, j](const Baggage& b) {
                return b.passengerNumber == passengers[j].number;
                });

            if (baggageItr1 != baggage.end() && baggageItr2 != baggage.end()) {
                // Check if the number of items is the same and weight difference is within the limit
                if (baggageItr1->numItems == baggageItr2->numItems &&
                    std::abs(baggageItr1->weight - baggageItr2->weight) <= maxWeightDifference) {
                    std::cout << "Passengers with similar bags:\n"
                         << passengers[i].name << " and " << passengers[j].name << "\n";
                    return true;
                }
            }
        }
    }
    std::cout << "No two passengers have bags that meet the criteria.\n";
    return false;
}


void writePassengersToFile(const std::vector<Passenger>& passengers, const std::string& filename) {
    std::ofstream file(filename);

    for (const auto& passenger : passengers) {
        file << passenger.number << ' ' << passenger.name << '\n';
    }

    file.close();
}


void writeBaggageToFile(const std::vector<Baggage>& baggage, const std::string& filename) {
    std::ofstream file(filename);

    for (const auto& bag : baggage) {
        file << bag.passengerNumber << ' ' << bag.numItems << ' ' << bag.weight << '\n';
    }

    file.close();
}


std::vector<Passenger> readPassengersFromFile(const std::string& filename) {
    std::vector<Passenger> passengers;
    std::ifstream file(filename);

    int number;
    std::string name;

    while (file >> number >> name) {
        passengers.push_back({ number, name });
    }

    file.close();
    return passengers;
}


std::vector<Baggage> readBaggageFromFile(const std::string& filename) {
    std::vector<Baggage> baggage;
    std::ifstream file(filename);

    int passengerNumber, numItems;
    double weight;

    while (file >> passengerNumber >> numItems >> weight) {
        baggage.push_back({ passengerNumber, numItems, weight });
    }

    file.close();
    return baggage;
}

int main() {
    std::vector<Passenger> passengers = {
        {1, "John"},
        {2, "Jane"},
        {3, "Bob"},
    };

    std::vector<Baggage> baggage = {
        {1, 2, 20.5},
        {2, 3, 22.0},
        {3, 2, 20.8},
    };
    writePassengersToFile(passengers, "passengers.txt");
    writeBaggageToFile(baggage, "baggage.txt");

    std::vector<Passenger> readPassengers = readPassengersFromFile("passengers.txt");
    std::vector<Baggage> readBaggage = readBaggageFromFile("baggage.txt");
    double maxWeightDifference = 2.0;
    haveSimilarBags(readPassengers, readBaggage, maxWeightDifference);

    return 0;
}