#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>

// Lab 14 task 2

int main() {
    freopen("data/lab14_task2.txt", "r", stdin);
    freopen("data/lab14_task2_out.txt", "w", stdout);
    
    bool change_letter = false;
    std::string w;
    while (std::cin >> w) {
        if (change_letter && !w.empty()) {
            w[0] = static_cast<unsigned char>(
                std::toupper(static_cast<unsigned char>(w[0]))
            );
        }
        change_letter = w == "die" || w == "der" || w == "das";
        std::cout << w << ' ';
    }
}