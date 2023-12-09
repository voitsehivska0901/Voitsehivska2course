#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>

// Lab 14 task 3

int main() {
    freopen("data/lab14_task3.txt", "r", stdin);
    freopen("data/lab14_task3_out.txt", "w", stdout);

    std::string w;
    while (std::cin >> w) {
        std::string_view word = w;
        for (size_t sep_beg = 0; sep_beg < word.size();) {
            size_t sep_size = 
                std::min(
                    std::min(
                        word.size(),
                        word.find(',', sep_beg)
                    ),
                    std::min(
                        word.find('!', sep_beg),
                        word.find('.', sep_beg)
                    )
                ) - sep_beg;

            for (size_t i = 0; i < sep_size/2; i++) {
                std::swap(w[sep_beg + i], w[sep_beg + sep_size -1-i]);
            }
            sep_size += 1;
            std::cout << w.substr(sep_beg, sep_size);
            sep_beg += sep_size;
        }
        std::cout << " ";
    }
}