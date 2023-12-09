#include <memory>
#include <string>
#include <iostream>

template<typename T>
class Stack {
    struct Node;

    using node_ptr = std::unique_ptr<Node>;
    
    struct Node {
        T el;
        node_ptr prev;
    };
public:
    Stack() noexcept = default;

    bool is_empty() const noexcept {
        return m_root == nullptr;
    }

    void push(const T& el) {
        m_root = std::make_unique<Node>(Node {
            .el = el,
            .prev = std::move(m_root)
        });
    }

    void push(T&& el) {
        m_root = std::make_unique<Node>(Node {
            .el = std::move(el),
            .prev = std::move(m_root)
        });
    }

    void pop() {
        m_root = std::move(m_root.get()->prev);
    }

    const T& top() const {
        return m_root.get()->el;
    }
private:
    node_ptr m_root = nullptr;
};

int main() {
    Stack<char> s;
    std::string buf;
    std::cin >> buf;
    for (char ch : buf) {
        s.push(ch);
    }
    
    while (!s.is_empty()) {
        std::cout << s.top();
        s.pop();
    }
}