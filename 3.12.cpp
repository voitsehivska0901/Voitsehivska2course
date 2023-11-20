#include <iostream>
#include <cmath>
#include <algorithm>


int main() {
    double a, b, c;
    std::cout << "Enter the sides of the triangle (a, b, c): ";
    std::cin >> a >> b >> c;

    double sides[3] = { a, b, c };
    std::sort(sides, sides + 3);
    if (std::abs(sides[0] * sides[0] + sides[1] * sides[1] - sides[2] * sides[2]) < 1e-6) {
        std::cout << "This is a rectangular triangle." << std::endl;
        return 0;
    }
    if (sides[0] * sides[0] + sides[1] * sides[1] > sides[2] * sides[2]) {
        std::cout << "This is an acute-angled triangle." << std::endl;
    }
    else {
        std::cout << "This is an obtuse triangle." << std::endl;
    }
}