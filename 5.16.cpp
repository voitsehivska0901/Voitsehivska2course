#include <iostream>
#include <cmath>

double approximateSinhSum(double x, double e) {
    double term = x;
    double sum = term;
    int k = 1;
    double factor = 1;
    double pow_x = x;

    while (std::abs(term) >= e) {
        factor *= (k + 1) * (k + 2);
        pow_x *= x * x;
        k += 2;
        term = pow_x / factor;
        if (std::abs(term) >= e) {
            sum += term;
        }
        
    }

    return sum;
}

int main() {
    double x, e;
    std::cout << "x = ";
    std::cin >> x;

    std::cout << "e = ";
    std::cin >> e;
    double result = approximateSinhSum(x, e);
    std::cout << "sinh(x) = " << result << std::endl;

    return 0;
}