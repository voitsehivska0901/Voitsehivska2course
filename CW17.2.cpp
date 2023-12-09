#include <string>

class Human {
public:
    Human() = default;

protected:
    std::string m_name;
    unsigned m_age;
    bool m_gender;
};

class Student: virtual public Human {
public:
    Student() = default;

protected:
    std::string university;
    unsigned course;
};

class Lecturer: virtual public Human {
public:
    Lecturer() = default;
};

class Postgraduate: public Student, Lecturer {
public:
    Postgraduate() = default;
};

int main() {

}