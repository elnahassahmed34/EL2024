# C++ Concepts

## Functions

### Overloading
Function overloading allows multiple functions to have the same name with different parameters. The correct function to be called is determined by the arguments provided.

```cpp
#include <iostream>

void print(int i) {
    std::cout << "Integer: " << i << std::endl;
}

void print(double f) {
    std::cout << "Double: " << f << std::endl;
}

void print(const std::string &s) {
    std::cout << "String: " << s << std::endl;
}

int main() {
    print(10);
    print(3.14);
    print("Hello, World!");
    return 0;
}
```

### Mangling
Name mangling is the process where the compiler generates unique names for each function based on their parameters. This allows function overloading to work. Mangled names are often compiler-specific.

### Ambiguous
Ambiguity occurs when the compiler cannot determine which overloaded function to call. This usually happens when the arguments provided match more than one function signature.

```cpp
#include <iostream>

void f(int i) { std::cout << "Integer: " << i << std::endl; }
void f(double d) { std::cout << "Double: " << d << std::endl; }
// void f(long l) { std::cout << "Long: " << l << std::endl; }

int main() {
    f(1);   // Ambiguous if the third function is uncommented
    return 0;
}
```

### std::function
std::function is a versatile function wrapper in the standard library that can hold any callable object.

```cpp
#include <iostream>
#include <functional>

void defaultFunction() {
    std::cout << "Default function called" << std::endl;
}

void runCallBack(std::function<void()> y = defaultFunction) {
    y();
}

int main() {
    runCallBack(); // Calls defaultFunction
    runCallBack([]() { std::cout << "Lambda function called" << std::endl; });
    return 0;
}
```

### std::array and Operations on It
std::array is a fixed-size array that is part of the standard library.

```cpp
#include <iostream>
#include <array>

int main() {
    std::array<int, 3> arr = {1, 2, 3};

    // Access elements
    std::cout << arr[0] << std::endl;

    // Size of the array
    std::cout << arr.size() << std::endl;

    // Iterate over elements
    for (const auto &elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
## Pointers
Pointers are variables that store the address of another variable.

### Pointer to Function
A pointer to a function can be used to store the address of a function and call it indirectly.

```cpp
#include <iostream>

void greet() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    void (*funcPtr)() = greet;
    funcPtr();
    return 0;
}
```
### References
References are aliases for other variables.

### Pass by Value vs Pointer vs Reference
Passing by value copies the data, passing by pointer passes the address, and passing by reference passes an alias.

```cpp
#include <iostream>

void byValue(int x) {
    x = 100;
}

void byPointer(int *x) {
    *x = 100;
}

void byReference(int &x) {
    x = 100;
}

int main() {
    int a = 10;
    byValue(a);
    std::cout << "By value: " << a << std::endl;

    byPointer(&a);
    std::cout << "By pointer: " << a << std::endl;

    byReference(a);
    std::cout << "By reference: " << a << std::endl;

    return 0;
}
```
## auto
auto is a type specifier that deduces the type of a variable from its initializer.

### Problems with Pointers and References
When using auto, care must be taken with pointers and references as it may deduce unexpected types.

```cpp
#include <iostream>

int main() {
    int a = 10;
    int *p = &a;

    auto x = p; // x is int*
    auto y = *p; // y is int

    std::cout << "x: " << x << ", y: " << y << std::endl;

    return 0;
}

```
### Problems with `auto` Keyword
When using `auto`, the deduced type might not always be what you expect, especially with references and pointers. 

```cpp
#include <iostream>

int main() {
    int a = 10;
    int& ref = a;
    int* ptr = &a;

    auto x = ref;  // x is int, not int&
    auto y = ptr;  // y is int*, which is expected

    x = 20;
    std::cout << "a: " << a << ", x: " << x << std::endl;

    return 0;
}
```
In this example, x is an int rather than an int&, so changes to x do not affect a.

## Casting
C++ provides several types of casting operators to handle different casting needs.

### C-Style Casting
C-style casting is the traditional way of casting in C.

```cpp
int a = 10;
double b = (double)a;
```
### static_cast
Used for well-defined and non-polymorphic conversions.

```cpp
int a = 10;
double b = static_cast<double>(a);
```

### dynamic_cast
Used for safe downcasting in class hierarchies.

```cpp
#include <iostream>

class Base {
    virtual void foo() {}
};

class Derived : public Base {};

int main() {
    Base* b = new Derived;
    Derived* d = dynamic_cast<Derived*>(b);
    if(d != nullptr) {
        std::cout << "Downcast successful" << std::endl;
    } else {
        std::cout << "Downcast failed" << std::endl;
    }

    delete b;
    return 0;
}
```
### const_cast
Used to add or remove const from a variable.

```cpp
void print(const int* x) {
    int* y = const_cast<int*>(x);
    *y = 20;
}

int main() {
    int a = 10;
    print(&a);
    std::cout << "a: " << a << std::endl;
    return 0;
}
```
### reinterpret_cast
Used for low-level reinterpreting of the bit pattern of an object.

```cpp
int a = 10;
char* b = reinterpret_cast<char*>(&a);
```