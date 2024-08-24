## 1. Try/Catch
Overview
- The try/catch mechanism in C++ is used for exception handling. It allows you to handle errors and exceptional situations gracefully without crashing the program.

Syntax
```cpp
try {
    // Code that might throw an exception
} catch (exception_type e) {
    // Code to handle the exception
}
```
Example
```cpp
#include <iostream>
#include <stdexcept>

int main() {
    try {
        int a = 10, b = 0;
        if (b == 0)
            throw std::runtime_error("Division by zero error");
        std::cout << a / b << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return 0;
}
```
### Key Points
- Exceptions are thrown using the throw keyword.
- The catch block handles the exception.
- The program can have multiple catch blocks to handle different types of exceptions.
## 2. RAII (Resource Acquisition Is Initialization)
Ov erview
- RAII is a programming idiom in C++ where resource allocation is tied to object lifetime. It ensures that resources are released when they are no longer needed, typically through destructors.

Example
```cpp
#include <iostream>
#include <fstream>

class FileHandler {
public:
    FileHandler(const std::string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file");
        }
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }

private:
    std::fstream file;
};

int main() {
    try {
        FileHandler fh("example.txt");
        // File operations...
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```
### Key Points
- RAII ties resource management (like file handles, memory, etc.) to the lifetime of objects.
- Resources are released automatically when the object goes out of scope.
## 3. Namespace
Overview
- Namespaces in C++ are used to avoid name conflicts by grouping entities like classes, objects, and functions under a name.

Syntax
```cpp
namespace namespace_name {
    // code declarations
}
Example
```cpp
#include <iostream>

namespace Math {
    int add(int a, int b) {
        return a + b;
    }
}

int main() {
    std::cout << "Sum: " << Math::add(5, 3) << std::endl;
    return 0;
}
```
### Key Points
- The namespace keyword is used to declare a namespace.
- You can access members of a namespace using the scope resolution operator ::.
## 4. New/Delete
Overview
- new and delete are used in C++ for dynamic memory allocation and deallocation.

Syntax
```cpp
int* ptr = new int; // allocate memory
delete ptr;         // deallocate memory
```
Example
```cpp
#include <iostream>

int main() {
    int* ptr = new int(10);
    std::cout << "Value: " << *ptr << std::endl;
    delete ptr;
    return 0;
}
```
### Key Points
- new allocates memory on the heap, and delete deallocates it.
- Always match new with delete to avoid memory leaks.

## 5. Smart Pointers
Overview
- Smart pointers are a type of object in C++ that manage the lifetime of dynamically allocated objects. They automatically deallocate the memory when it's no longer needed.

Types
- std::unique_ptr: Owns an object exclusively.
- std::shared_ptr: Multiple smart pointers can share ownership of the same object.
- std::weak_ptr: A weak reference to an object managed by std::shared_ptr.
Example
```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> uptr(new int(10));
    std::cout << "Value: " << *uptr << std::endl;

    std::shared_ptr<int> sptr1 = std::make_shared<int>(20);
    std::shared_ptr<int> sptr2 = sptr1;
    std::cout << "Shared Value: " << *sptr1 << std::endl;

    return 0;
}
```
### Key Points
- Smart pointers help avoid memory leaks by automatically managing the object's lifetime.
- std::unique_ptr cannot be copied, only moved.
- std::shared_ptr allows shared ownership, meaning multiple pointers can point to the same object.

## 6. Template (Function, Class, Variadic)
Overview
- Templates in C++ allow writing generic functions and classes that can work with any data type.

### Function Template
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Sum: " << add(5, 3) << std::endl;
    return 0;
}
```
### Class Template
```cpp
template <typename T>
class Box {
public:
    Box(T value) : value(value) {}
    T getValue() { return value; }

private:
    T value;
};

int main() {
    Box<int> intBox(10);
    std::cout << "Boxed Value: " << intBox.getValue() << std::endl;
    return 0;
}
```
### Variadic Template
```cpp
#include <iostream>

template<typename T>
void print(T t) {
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    std::cout << t << " ";
    print(args...);
}

int main() {
    print(1, 2.5, "hello");
    return 0;
}
```
### Key Points
- Templates allow code reusability and flexibility.
- Variadic templates can accept multiple arguments of different types.
## 7. Tuple and Pair
### Tuple
Overview
- A std::tuple is a fixed-size collection of heterogeneous values. It can store multiple values of different types.

Example
```cpp
#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, double, std::string> tup(1, 2.5, "Hello");
    std::cout << "Int: " << std::get<0>(tup) << ", Double: " << std::get<1>(tup) << ", String: " << std::get<2>(tup) << std::endl;
    return 0;
}
```
### Pair
Overview
- A std::pair is a container that stores two heterogeneous values as a single unit.

Example
```cpp
#include <iostream>
#include <utility>

int main() {
    std::pair<int, std::string> p(1, "Hello");
    std::cout << "First: " << p.first << ", Second: " << p.second << std::endl;
    return 0;
}
```

### Key Points
- std::tuple can store more than two values, whereas std::pair can only store two.
- Both tuple and pair are useful for returning multiple values from functions.