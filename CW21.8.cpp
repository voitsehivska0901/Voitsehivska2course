#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <string_view>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::string_view> parts;
    size_t l = 0;
    while (l < s.size()) {
        while(l < s.size() && std::isspace(s[l])) l++;
        if (l == s.size()) break;
        size_t r = l;
        while(r < s.size() && !std::isspace(s[r])) r++;
        parts.push_back(std::string_view(s).substr(l, r-l));
        l = r;
    }
    std::sort(parts.begin(), parts.end());
    std::cout << "-----------------------\n";
    do {
        for (auto v : parts) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    } while(std::next_permutation(parts.begin(), parts.end()));
}