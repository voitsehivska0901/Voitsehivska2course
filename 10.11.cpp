#include <iostream>
#include <vector>
#include <string>

struct Citizen {
    std::string name;
    std::string city;
    std::string street;
    int house;
    int apartment;
};

void searchResidents(const std::vector<Citizen>& citizens) {
    int n = citizens.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (citizens[i].street == citizens[j].street &&
                citizens[i].house == citizens[j].house &&
                citizens[i].apartment == citizens[j].apartment &&
                citizens[i].city != citizens[j].city) {
                std::cout << "Residents with the same address but different cities found:\n";
                std::cout << "Name: " << citizens[i].name << ", City: " << citizens[i].city << "\n";
                std::cout << "Name: " << citizens[j].name << ", City: " << citizens[j].city << "\n";
                return;
            }
        }
    }
    std::cout << "No residents with the same address but different cities found.\n";
}

int main() {

    std::vector<Citizen> residents = {
        {"John", "CityA", "Main St", 123, 456},
        {"Alice", "CityB", "Main St", 123, 456},
        {"Bob", "CityA", "Side St", 789, 101},
    };
    searchResidents(residents);

    return 0;
}