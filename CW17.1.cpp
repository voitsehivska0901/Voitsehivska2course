#include <iostream>
#include <numeric>
#include <compare>
#include <exception>
#include <stdexcept>

class WrongRatio: public std::invalid_argument {
public:
    WrongRatio() : std::invalid_argument("wrong ratio: denominator can't be zero") {}
};

class InvalidRatioStr: public std::runtime_error {
public:
    InvalidRatioStr() : std::runtime_error("invalid ratio string") {}
};

class Rational {
public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(Rational&&) = default;
    
    Rational(int nominator, unsigned denominator) : m_nominator(nominator), m_denominator(denominator) {
        if (m_denominator == 0)
            throw WrongRatio();
        this->reduce();
    }
    
    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    ~Rational() = default;

    void set_nominator(int nominator) {
        this->m_nominator = nominator;
    }

    void set_denominator(unsigned denominator) {
        if (denominator == 0)
            throw WrongRatio();
        this->m_denominator = denominator;
    }

    friend Rational operator-(const Rational&) noexcept;
    friend Rational operator+(const Rational&, const Rational&) noexcept;
    friend Rational operator-(const Rational&, const Rational&) noexcept;
    friend Rational operator*(const Rational&, const Rational&) noexcept;
    friend Rational operator/(const Rational&, const Rational&) noexcept;

    friend std::strong_ordering operator<=>(const Rational&, const Rational&) noexcept;

    friend std::ostream& operator<<(std::ostream&, const Rational&) noexcept;
    friend std::istream& operator>>(std::istream&, Rational&);
protected:
    void reduce() noexcept {
        unsigned nom = std::abs(m_nominator);
        unsigned common = std::gcd(nom, m_denominator);
        m_nominator /= common;
        m_denominator /= common;
    }

    int m_nominator{0};
    unsigned m_denominator{1};
};

Rational operator-(const Rational& a) noexcept {
    return Rational(-a.m_nominator, a.m_denominator);
}

Rational operator+(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * static_cast<int>(b.m_denominator) + b.m_nominator * static_cast<int>(a.m_denominator);
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator-(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * static_cast<int>(b.m_denominator) - b.m_nominator * static_cast<int>(a.m_denominator);
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator*(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_nominator;
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator/(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_denominator;
    unsigned denom = a.m_denominator * b.m_nominator;
    return Rational(nom, denom);
}

std::strong_ordering operator<=>(const Rational& a, const Rational& b) noexcept {
    return a.m_nominator * static_cast<int>(b.m_denominator) <=> b.m_nominator * static_cast<int>(a.m_denominator);
}

std::ostream& operator<<(std::ostream& out, const Rational& r) noexcept {
    return out << r.m_nominator << "/" << r.m_denominator;
}

std::istream& operator>>(std::istream& in, Rational& r) {
    int nom = 0;
    unsigned denom = 1;
    char sep;
    in >> nom >> sep >> denom;
    if (sep != '/' || in.bad()) {
        throw InvalidRatioStr();
    }
    r = Rational(nom, denom);
    return in;
}

int main() {
    try {
        Rational r;
        std::cin >> r;
        std::cout << r;
    } catch (WrongRatio& r) {
        std::cout << r.what() << std::endl;
    } catch (InvalidRatioStr& r) {
        std::cout << r.what() << std::endl;
    }
}