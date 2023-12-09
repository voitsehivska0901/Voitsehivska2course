#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << std::endl;
    } while(std::next_permutation(s.begin(), s.end()));
}