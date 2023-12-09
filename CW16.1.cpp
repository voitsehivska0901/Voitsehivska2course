#include <iostream>
#include <vector>

// Lab 16 task 1

class Person {
public:
    Person() = default;
    Person(const Person&) = default;
    Person(Person&&) = default;
    Person& operator=(const Person&) = default;
    Person& operator=(Person&&) = default;
    ~Person() = default;

    int input() {
        std::cin >> *this;
        return 1;
    }
    void show() const {
        std::cout << *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Person& p);
    friend std::istream& operator>>(std::istream& in, Person& p);

    unsigned byear() const {
        return m_byear;
    }
    const std::string& name() const {
        return m_name;
    }
private:
    std::string m_name;
    unsigned m_byear{};
};

std::ostream& operator<<(std::ostream& out, const Person& p) {
    return out << "`" << p.m_name << "`: `" << p.m_byear << "`";
}

std::istream& operator>>(std::istream& in, Person& p) {
    return in >> p.m_name >> p.m_byear;
}

class Friend : public Person {
public:
    Friend() = default;
    Friend(const Friend&) = default;
    Friend(Friend&&) = default;
    Friend& operator=(const Friend&) = default;
    Friend& operator=(Friend&&) = default;
    ~Friend() = default;

    unsigned number() const {
        return m_number;
    }
    void set_number(unsigned new_number) {
        m_number = new_number;
    }

    int input() {
        std::cin >> *static_cast<Person*>(this) >> m_number;
        return 1;
    }
    void show() const {
        std::cout << *static_cast<const Person*>(this) << ", `" << m_number << "`";
    }
private:
    unsigned m_number{};
};

int main() {
    std::vector<Friend> friend_list;

    while (true) {
        std::cout << 
R"(choose operation:
0 - exit
usage: 0
1 - add new friend
usage: 1 [name] [byear] [number]
2 - find number by name
usage: 2 [name]
3 - change number by name
usage: 2 [name] [new_number]
)";
        unsigned op;
        std::cin >> op;
        if (op == 0) break;
        switch(op) {
        case 1: {
            Friend f;
            f.input();
            friend_list.emplace_back(std::move(f));
        } break;
        case 2: {
            std::string name;
            std::cin >> name;
            for (const auto& f : friend_list) {
                if (name == f.name()) {
                    std::cout << f.number() << std::endl;
                }
            }
        } break;
        case 3: {
            std::string name;
            unsigned new_number;
            std::cin >> name >> new_number;
            for (auto& f : friend_list) {
                if (name == f.name()) {
                    f.set_number(new_number);
                }
            }
        } break;
        default:
            std::cout << "invalid operation: `" << op << "`\n";
            break;
        }
    }
}