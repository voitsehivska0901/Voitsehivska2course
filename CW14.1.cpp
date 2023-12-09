#include <iostream>
#include <cstdio>
#include <string>

// Lab 14 task 1

int main() {
    freopen("data/lab14_task1.txt", "r", stdin);
    double value;
    std::cin >> value;
    while (true) {    
        char op;
        std::cin >> op;
        if (op == '=') {
            break;
        } else {
            if (op == '+') {
                double d;
                std::cin >> d;
                value += d;
            }
            if (op == '-') {
                double d;
                std::cin >> d;
                value -= d;
            }
        }
    }
    std::cout << value << '\n';
}  