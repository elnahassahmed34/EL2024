#include <iostream>

class MyInteger {
private:
    int value;

public:
    // Default constructor
    MyInteger() : value(0) {}

    // Parameterized constructor
    MyInteger(int v) : value(v) {}

    // Copy constructor
    MyInteger(const MyInteger& other) : value(other.value) {}

    // Move constructor
    MyInteger(MyInteger&& other) noexcept : value(other.value) {}

    // Destructor
    ~MyInteger() = default;

    // Copy assignment operator
    MyInteger& operator=(const MyInteger& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Move assignment operator
    MyInteger& operator=(MyInteger&& other) noexcept {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Addition operator
    MyInteger operator+(const MyInteger& other) const {
        return MyInteger(value + other.value);
    }

    // Comparison operator
    bool operator==(const MyInteger& other) const {
        return value == other.value;
    }

    // Print value
    void print() const {
        std::cout << value;
    }
};

int main() {
    MyInteger num1(10);
    MyInteger num2(20);
    MyInteger num3 = num1 + num2;

    num3.print(); // Output: 30

    if (num3 == MyInteger(30)) {
        std::cout << "num3 is 30" << std::endl;
    }

    return 0;
}

