#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

// Lab 14 task 5

void create_example_file() {
    constexpr std::string_view data = R"(
yudin, 2, comp math 1, 30, 29, 20, 29
mus, 2, comp math 1, 20, 10, 30, 5,
nedilya, 2, comp math 1, 30, 30, 30, 30
)";

    std::ofstream("data/lab14_task5_out1.txt") << data;
}

int main() {
    create_example_file();

    std::ifstream data_in("data/lab14_task5_out1.txt");
    std::string buf;
    std::string student;
    double av = 30.;
    while (!data_in.eof()) {
        std::getline(data_in, buf);
        size_t surname_end = buf.find(',');
        size_t group_end = buf.find(',', surname_end+1);
        size_t subgroup_end = buf.find(',', group_end+1);
        double average_mark = 0.;
        int marks = 0;
        for (size_t mark_beg = subgroup_end; mark_beg < buf.size();) {
            average_mark += std::strtod(buf.data() + mark_beg, nullptr);
            marks += 1;
            mark_beg = buf.find(',', mark_beg+1);
        }
        if (average_mark / marks < av) {
            student = buf.substr(0, surname_end-1);
            av = average_mark / marks;
        }
    }
    std::cout << student;
}