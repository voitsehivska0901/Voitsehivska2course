#include <iostream>

struct Time {
    int hour;
    int minute;
    int second;

    Time() {
        input();
    }
    void input() {
        std::cout << "Enter hour: ";
        std::cin >> hour;

        std::cout << "Enter minute: ";
        std::cin >> minute;

        std::cout << "Enter second: ";
        std::cin >> second;
    }
    void output() const {
        std::cout << "Time: " << hour << ":" << minute << ":" << second << std::endl;
    }
    void adjustTime() {
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;
    }
};

int main() {
    Time myTime;
    myTime.adjustTime();
    myTime.output();

    return 0;
}