#include <iostream>
#include <sstream>
#include <vector>


void printWordsEndingWith(const std::string& sentence, char endingChar) {
    std::istringstream iss(sentence);
    std::string word;
    std::vector<std::string> words;
    while (std::getline(iss, word, ' ')) {
        while (!word.empty() && (word.back() == ',' || word.back() == ' ')) {
            word.pop_back();
        }

        words.push_back(word);
    }

    for (const std::string& w : words) {
        if (!w.empty() && w.back() == endingChar) {
            std::cout << w << '\n';
        }
    }
}

int main() {
    std::cout << "Enter a sentence: ";
    std::string sentence;
    std::getline(std::cin, sentence);

    std::cout << "Enter a last character: ";
    char endingChar;
    std::cin >> endingChar;
    printWordsEndingWith(sentence, endingChar);

    return 0;
}