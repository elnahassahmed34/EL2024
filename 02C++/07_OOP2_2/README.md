# C++ Advanced Concepts
## 1. Copy Constructor
### Shallow Copy
A shallow copy of an object copies all the member field values. If the field values include pointers, the addresses are copied. This means that the new object and the original object will point to the same memory locations.

Example:
```cpp
class ShallowCopyExample {
public:
    int* data;

    ShallowCopyExample(int value) {
        data = new int(value);
    }

    // Shallow copy constructor
    ShallowCopyExample(const ShallowCopyExample& other) {
        data = other.data;
    }

    ~ShallowCopyExample() {
        delete data;
    }
};
```
### Deep Copy
A deep copy duplicates everything. If the object has pointers to dynamic memory, it allocates separate memory for the copy.

Example:
```cpp
class DeepCopyExample {
public:
    int* data;

    DeepCopyExample(int value) {
        data = new int(value);
    }

    // Deep copy constructor
    DeepCopyExample(const DeepCopyExample& other) {
        data = new int(*other.data);
    }

    ~DeepCopyExample() {
        delete data;
    }
};
```
## 2. -fno-elide-constructors
The -fno-elide-constructors compiler option disables the optimization where temporary objects are not constructed. This is useful for testing and learning about how many times constructors are called.

Example:
```sh
g++ -fno-elide-constructors main.cpp -o main
```
## 3. Operator =
The assignment operator (=) is used to assign the values from one object to another already existing object. When overloading this operator, it is important to handle self-assignment and free existing resources if necessary.

Example:
```cpp
class AssignmentExample {
public:
    int* data;

    AssignmentExample(int value) {
        data = new int(value);
    }

    // Assignment operator
    AssignmentExample& operator=(const AssignmentExample& other) {
        if (this == &other) return *this; // handle self-assignment
        delete data;                      // free existing resource
        data = new int(*other.data);      // allocate new memory and copy
        return *this;
    }

    ~AssignmentExample() {
        delete data;
    }
};
```
## 4. Rule of Three / Rule of Five
### Rule of Three
If a class requires a user-defined destructor, copy constructor, or copy assignment operator, it almost certainly requires all three.

Example:
```cpp
class RuleOfThreeExample {
public:
    int* data;

    RuleOfThreeExample(int value) {
        data = new int(value);
    }

    // Destructor
    ~RuleOfThreeExample() {
        delete data;
    }

    // Copy Constructor
    RuleOfThreeExample(const RuleOfThreeExample& other) {
        data = new int(*other.data);
    }

    // Copy Assignment Operator
    RuleOfThreeExample& operator=(const RuleOfThreeExample& other) {
        if (this == &other) return *this;
        delete data;
        data = new int(*other.data);
        return *this;
    }
};
```
### Rule of Five
If a class requires a user-defined destructor, copy constructor, copy assignment operator, move constructor, or move assignment operator, it almost certainly requires all five.

Example:
```cpp
class RuleOfFiveExample {
public:
    int* data;

    RuleOfFiveExample(int value) {
        data = new int(value);
    }

    // Destructor
    ~RuleOfFiveExample() {
        delete data;
    }

    // Copy Constructor
    RuleOfFiveExample(const RuleOfFiveExample& other) {
        data = new int(*other.data);
    }

    // Copy Assignment Operator
    RuleOfFiveExample& operator=(const RuleOfFiveExample& other) {
        if (this == &other) return *this;
        delete data;
        data = new int(*other.data);
        return *this;
    }

    // Move Constructor
    RuleOfFiveExample(RuleOfFiveExample&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }

    // Move Assignment Operator
    RuleOfFiveExample& operator=(RuleOfFiveExample&& other) noexcept {
        if (this == &other) return *this;
        delete data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }
};
```
## 5. Value Categories
### Lvalue
An lvalue refers to an object that persists beyond a single expression.

### Rvalue
An rvalue is a temporary object that does not persist beyond the expression that uses it.

## 6. Type Categories
### Lvalue Reference
A reference that binds to an lvalue.

```cpp
int x = 10;
int& ref = x; // ref is an lvalue reference to x
```
### Rvalue Reference
A reference that binds to an rvalue.

```cpp
int&& rref = 10; // rref is an rvalue reference to a temporary 10
```
## 7. Rvalue Reference Constructor
An rvalue reference constructor is used to implement move semantics.

Example:
```cpp
class RvalueConstructorExample {
public:
    int* data;

    RvalueConstructorExample(int value) {
        data = new int(value);
    }

    // Move constructor
    RvalueConstructorExample(RvalueConstructorExample&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }

    ~RvalueConstructorExample() {
        delete data;
    }
};
```
## 8. Operator Rvalue Reference
You can also overload operators to work with rvalue references.

Example:
```cpp
class OperatorRvalueRefExample {
public:
    int* data;

    OperatorRvalueRefExample(int value) {
        data = new int(value);
    }

    // Move assignment operator
    OperatorRvalueRefExample& operator=(OperatorRvalueRefExample&& other) noexcept {
        if (this == &other) return *this;
        delete data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }

    ~OperatorRvalueRefExample() {
        delete data;
    }
};
```
## 9. Rule of Zero
The Rule of Zero states that you should rely on the compiler-generated versions of the special member functions (destructor, copy constructor, copy assignment operator, move constructor, and move assignment operator) if possible, by using RAII (Resource Acquisition Is Initialization) principles and smart pointers.


task :
1- Create Class behave like String/Integer totally

2-Create Class to handle Logs with different Levels and store Msgs as well for dump and clear the
buffer
LOG::Level(level::warn)<<” forget to close file “ ;
LOG::Dump();
LOG::Clear

3-create a class git Manager