#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Employee {
    std::string firstName;
    std::string lastName;
    char gender;
    int birthDay;
    int birthMonth;
    int birthYear;
    std::string position;
};

std::string findMostPopularPosition(const std::vector<Employee>& employees) {
    std::map<std::string, int> positionCount;
    for (const auto& employee : employees) {
        positionCount[employee.position]++;
    }
    std::string mostPopularPosition;
    int maxCount = 0;

    for (const auto& entry : positionCount) {
        if (entry.second > maxCount) {
            mostPopularPosition = entry.first;
            maxCount = entry.second;
        }
    }

    return mostPopularPosition;
}

std::vector<std::pair<Employee, Employee>> findEmployeesWithSameFirstName(const std::vector<Employee>& employees) {
    std::vector<std::pair<Employee, Employee>> result;
    for (size_t i = 0; i < employees.size() - 1; i++) {
        for (size_t j = i + 1; j < employees.size(); j++) {
            if (employees[i].firstName == employees[j].firstName) {
                result.push_back({ employees[i], employees[j] });
            }
        }
    }

    return result;
}

std::vector<Employee> findEmployeesWithLastNameStartingWithLetter(const std::vector<Employee>& employees, char targetLetter) {
    std::vector<Employee> result;

    for (const auto& employee : employees) {
        if (!employee.lastName.empty() && std::toupper(employee.lastName[0]) == std::toupper(targetLetter)) {
            result.push_back(employee);
        }
    }
    return result;
}

Employee findMostSeniorMan(const std::vector<Employee>& employees) {
    Employee mostSeniorMan;
    bool found = false;
    for (const auto& employee : employees) {
        if (employee.gender == 'M') {
            if (!found || (employee.birthYear < mostSeniorMan.birthYear) ||
                (employee.birthYear == mostSeniorMan.birthYear && employee.birthMonth < mostSeniorMan.birthMonth) ||
                (employee.birthYear == mostSeniorMan.birthYear && employee.birthMonth == mostSeniorMan.birthMonth && employee.birthDay < mostSeniorMan.birthDay)) {
                mostSeniorMan = employee;
                found = true;
            }
        }
    }

    return mostSeniorMan;
}

std::vector<Employee> findYoungerEmployees(const std::vector<Employee>& employees) {
    std::vector<Employee> result;

    if (employees.empty()) {
        return result;
    }

    int currentYear = 2023;
    double totalAge = 0.0;

    for (const auto& employee : employees) {
        totalAge += (currentYear - employee.birthYear);
    }

    double averageAge = totalAge / employees.size();
    for (const auto& employee : employees) {
        if ((currentYear - employee.birthYear) < averageAge) {
            result.push_back(employee);
        }
    }

    return result;
}

int main() {

    std::vector<Employee> employees = {
        {"John", "Doe", 'M', 15, 3, 1980, "Manager2"},
        {"Jane", "Doe2", 'F', 20, 5, 1985, "Engineer"},
        {"Bob", "Smith", 'M', 10, 8, 1975, "Analyst"},
        {"Alice", "Jones", 'F', 5, 2, 1988, "Manager"},
        {"John", "Smith", 'M', 12, 6, 1982, "Engineer"},
    };

    std::string mostPopularPosition = findMostPopularPosition(employees);
    std::cout << "Most popular position: " << mostPopularPosition << "\n\n";

    std::vector<std::pair<Employee, Employee>> sameFirstNamePairs = findEmployeesWithSameFirstName(employees);
    std::cout << "Pairs of workers with the same first name:\n";
    for (const auto& pair : sameFirstNamePairs) {
        std::cout << "- " << pair.first.firstName << " " << pair.first.lastName
            << " and " << pair.second.firstName << " " << pair.second.lastName << "\n";
    }
    std::cout << "\n";

    char targetLetter = 'D';
    std::vector<Employee> lastNameStartsWithLetterEmployees = findEmployeesWithLastNameStartingWithLetter(employees, targetLetter);
    std::cout << "Employees whose last names begin with the letter \"" << targetLetter << "\":\n";
    for (const auto& employee : lastNameStartsWithLetterEmployees) {
        std::cout << "- " << employee.firstName << " " << employee.lastName << "\n";
    }
    std::cout << "\n";

    Employee mostSeniorMan = findMostSeniorMan(employees);
    std::cout << "Most senior man in the institution:\n";
    if (mostSeniorMan.firstName.empty()) {
        std::cout << "No male employees found.\n";
    }
    else {
        std::cout << "- " << mostSeniorMan.firstName << " " << mostSeniorMan.lastName << "\n";
    }
    std::cout << "\n";

    std::vector<Employee> youngerEmployees = findYoungerEmployees(employees);
    std::cout << "Employees younger than the average age in the organization:\n";
    for (const auto& employee : youngerEmployees) {
        std::cout << "- " << employee.firstName << " " << employee.lastName << "\n";
    }
}