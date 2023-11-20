#include <iostream>
#include <cmath>

const double epsilon = 1e-6;
double sinc(double x) {
    if (std::abs(x) < epsilon) {
        return 1.0;
    }
    else {
        return std::sin(x) / x;
    }
}

double sincDerivative(double x) {
    if (std::abs(x) < epsilon) {
        return 0.0;
    }
    else {
        return (x * std::cos(x) - std::sin(x)) / (x * x);
    }
}

int main() {
    double x;
    std::cin >> x;
    std::cout << "sinc= " << sinc(x) << std::endl;
    std::cout << "derivative= " << sincDerivative(x) << std::endl;

    return 0;
}