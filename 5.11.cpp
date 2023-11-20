#include <iostream>
#include <vector>

int calculateTerm(int k, int ak_minus_1, int ak_minus_2) {
    return ak_minus_1 + k * ak_minus_2;
}
int calculateSum(int n) {
    if (n <= 0) {
        return 0;
    }

    int a1 = 0;
    int a2 = 1;
    int sum = 4;
    int power_of_two = 4;

    for (int k = 3; k <= n; ++k) {
        int ak = calculateTerm(k, a2, a1);
        power_of_two *= 2;
        sum += power_of_two * ak;
        a1 = a2;
        a2 = ak;
    }

    return sum;
}

int main() {
    int n;
    std::cout << "n: ";
    std::cin >> n;
    int result = calculateSum(n);
    std::cout << "S = " << result << std::endl;

    return 0;
}