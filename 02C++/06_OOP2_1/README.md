# C++ Concepts: Operator Overloading, Functors, and `explicit` Keyword

## Operator Overloading

### Postfix and Prefix Operators

Operator overloading allows the definition of custom behaviors for operators in user-defined types.

- **Prefix Increment/Decrement (`++x`, `--x`)**

```cpp
  class Counter {
  private:
      int value;
  public:
      Counter(int v = 0) : value(v) {}
      // Prefix increment
      Counter& operator++() {
          ++value;
          return *this;
      }
      // Prefix decrement
      Counter& operator--() {
          --value;
          return *this;
      }
      int getValue() const { return value; }
  };
```
### Postfix Increment/Decrement (x++, x--)
```cpp
class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}
    // Postfix increment
    Counter operator++(int) {
        Counter temp = *this;
        ++value;
        return temp;
    }
    // Postfix decrement
    Counter operator--(int) {
        Counter temp = *this;
        --value;
        return temp;
    }
    int getValue() const { return value; }
};
```
## Conversion Operators
Conversion operators enable implicit or explicit conversion of a user-defined type to another type.

```cpp
class Integer {
private:
    int value;
public:
    Integer(int v) : value(v) {}
    // Conversion operator to int
    operator int() const {
        return value;
    }
};
```
## Friend Operator Overloading
Friend functions can be used to overload operators that need access to the private and protected members of a class.

```cpp
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    // Friend function for overloading +
    friend Complex operator+(const Complex &c1, const Complex &c2) {
        return Complex(c1.real + c2.real, c1.imag + c2.imag);
    }
};
```
## Functors (Function Objects)
A functor is an object that can be called as if it were a function, using the operator().

```cpp
#include <iostream>

class Multiply {
private:
    int factor;
public:
    Multiply(int f) : factor(f) {}
    // Overloading operator() to make Multiply a functor
    int operator()(int x) const {
        return x * factor;
    }
};

int main() {
    Multiply mul(5);
    std::cout << mul(10) << std::endl; // Outputs 50
}
```

## explicit Keyword
The explicit keyword prevents implicit conversions and copy-initialization, which can help avoid unintended conversions.

```cpp
class Point {
private:
    int x, y;
public:
    // Prevent implicit conversion from int to Point
    explicit Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

int main() {
    Point p = Point(10, 20); // OK
    // Point p2 = {30, 40}; // Error without `explicit`
}
```