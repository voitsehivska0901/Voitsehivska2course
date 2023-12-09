#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>

int main() {
    std::string s;
    std::cin >> s;
    std::transform(s.begin(), s.end(), s.begin(), [](char ch){
        return static_cast<char>(static_cast<unsigned char>(std::toupper(static_cast<unsigned char>(ch))));
    });
    std::cout << s;
}