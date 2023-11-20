#include <iostream>

double calculateXk(double x, int k) {
    double result = 1.0;

    for (int i = 1; i <= k; ++i) {
        result *= -1.0;
        result *= x;
        result /= i;
    }

    return result;
}

int main() {
    double x;
    int k;
    std::cin >> x >> k;
    std::cout << "x_" << k << " = " << calculateXk(x, k) << std::endl;

    return 0;
}