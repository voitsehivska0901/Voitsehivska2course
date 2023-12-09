#include <iostream>
#include <type_traits>
#include <cmath>

// Lab 16 task 2

struct Point {
    using dimensions = std::integral_constant<unsigned, 2>;

    double x, y;
};

struct Point3D: Point {
    using dimensions = std::integral_constant<unsigned, 3>;

    double z;
};

template<typename P>
struct Segment {
    P a, b;

    double length() const {
        if constexpr (P::dimensions::value == 2) {
            return std::hypot(a.x - b.x, a.y - b.y);
        } else if constexpr (P::dimensions::value == 3) {
            return std::hypot(a.x - b.x, a.y - b.y, a.z - b.z);
        } else {
            return 0.;
        }
    }
};


template<typename P>
std::ostream& operator<<(std::ostream& out, const Segment<P>& s) {
    if constexpr (P::dimensions::value == 2) {
        out << "(" << s.a.x << ", " << s.a.y << ")";
        out << "(" << s.b.x << ", " << s.b.y << ")";
    } else if constexpr (P::dimensions::value == 3) {
        out << "(" << s.a.x << ", " << s.a.y << ", " << s.a.z << ")";
        out << "(" << s.b.x << ", " << s.b.y << ", " << s.b.z << ")";
    }
    return out;
}

template<typename P>
std::istream& operator>>(std::istream& in, Segment<P>& s) {
    if constexpr (P::dimensions::value == 2) {
        in >> s.a.x >> s.a.y;
        in >> s.b.x >> s.b.y;
    } else if constexpr (P::dimensions::value == 3) {
        in >> s.a.x >> s.a.y >> s.a.z;
        in >> s.b.x >> s.b.y >> s.b.z;
    }
    return in;
}

int main() {
    Segment<Point> s1;
    Segment<Point3D> s2;

    std::cin >> s1;
    std::cin >> s2;

    std::cout << "`" << s1 << "`, `" << s2 << "`\n";
    std::cout << s1.length() << ", " << s2.length() << "\n";
}