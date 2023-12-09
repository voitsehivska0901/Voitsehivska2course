#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

// Lab 14 task 4

int main() {
    freopen("data/lab14_task4.txt", "r", stdin);

    std::string s;
    std::vector<std::string> tag_stack;
    while (std::cin >> s) {
        if (s.starts_with('<')) {
            if (!s.ends_with('>')) {
                std::cout << "incorrect: missing `>`\n";
                return 1;
            }
            if (s.starts_with("</")) {
                if (tag_stack.empty()) {
                    std::cout << "incorrect: no open tag\n";
                    return 1;
                }
                if (tag_stack.back() != std::string_view(s).substr(2, s.size()-3)) {
                    std::cout << "incorrect: tags doesn't match\n";
                    return 1;
                }
                tag_stack.pop_back();
            } else {
                tag_stack.push_back(s.substr(1, s.size()-2));
            }
        }
    }
    std::cout << "correct\n";
}