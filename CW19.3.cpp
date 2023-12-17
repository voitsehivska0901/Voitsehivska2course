#include <list>

template<typename T>
class Poly {
public: 
    Poly() noexcept = default;
    Poly(Poly&&) noexcept = default;
    Poly(const Poly&) = default;
    Poly& operator=(Poly&&) noexcept = default;
    Poly& operator=(const Poly&) = default;
    ~Poly() = default;

    // TODO input, constructor
private:
    std::list<std::pair<int, T>> powers;
};

int main() {
    // TODO
}