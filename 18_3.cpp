#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

template <typename T>
class BlackBox {
private:
    static const int maxSize = 100;
    std::vector<T> elements;

public:
    BlackBox() {
        std::srand(std::time(0));
    }
    BlackBox(const T* arr, int size) {
        if (size > maxSize) {
            throw std::out_of_range("Exceeded maximum size");
        }

        elements.assign(arr, arr + size);
        std::srand(std::time(0));
    }
    void push(const T& element) {
        if (elements.size() < maxSize) {
            elements.push_back(element);
        }
        else {
            throw std::out_of_range("Exceeded maximum size");
        }
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("BlackBox is empty");
        }
        int indexToRemove = std::rand() % elements.size();
        T removedElement = elements[indexToRemove];
        elements.erase(elements.begin() + indexToRemove);

        return removedElement;
    }

    T xpop() const {
        if (elements.empty()) {
            throw std::out_of_range("BlackBox is empty");
        }

        int randomIndex = std::rand() % elements.size();
        return elements[randomIndex];
    }
};

int main() {
    BlackBox<int> intBox;
    intBox.push(1);
    intBox.push(2);
    intBox.push(3);

    try {
        int removedValue = intBox.pop();
        std::cout << "Removed element value: " << removedValue << std::endl;

        std::cout << "Random element: " << intBox.xpop() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}