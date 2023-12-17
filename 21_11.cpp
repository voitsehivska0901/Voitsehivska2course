#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <set>

int main() {
    std::ifstream file1("1.txt");
    std::ifstream file2("2.txt");
    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }
    std::istream_iterator<std::string> file1Begin(file1), file1End;
    std::set<std::string> set1(file1Begin, file1End);
    std::istream_iterator<std::string> file2Begin(file2), file2End;
    std::set<std::string> set2(file2Begin, file2End);

    std::set<std::string> commonWords;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
        std::inserter(commonWords, commonWords.begin()));
    std::set<std::string> uncommonWords;
    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
        std::inserter(uncommonWords, uncommonWords.begin()));

    std::cout << "Common words:\n";
    for (const auto& word : commonWords) {
        std::cout << word << '\n';
    }
    std::cout << "\nUncommon words:\n";
    for (const auto& word : uncommonWords) {
        std::cout << word << '\n';
    }

    return 0;
}