# C++ Concepts

## Constructors

### Default Constructor
A default constructor is a constructor that can be called without any arguments. If no constructor is explicitly defined, the compiler provides a default constructor.

```cpp
class Example {
public:
    Example() {
        // Default constructor
    }
};
```
### Parameterized Constructor
A parameterized constructor is one that takes arguments to initialize an object with specific values.

```cpp
class Example {
public:
    int value;
    Example(int v) : value(v) {
        // Parameterized constructor
    }
};
```
### Delegating Constructor
In C++11 and later, a constructor can delegate to another constructor in the same class, simplifying code by reducing duplication.

```cpp
class Example {
public:
    int value;
    Example() : Example(0) {} // Delegates to parameterized constructor
    Example(int v) : value(v) {
        // Parameterized constructor
    }
};
```
## const with Members, Methods, and Objects
### const with Members
When a member variable is declared as const, it must be initialized when the object is created, typically via an initializer list.

```cpp
class Example {
public:
    const int value;
    Example(int v) : value(v) {
        // Constructor initializing const member
    }
};
```
### const with Methods
A const method guarantees that it will not modify any member variables of the class. It can be called on const objects.

```cpp
class Example {
public:
    int value;
    Example(int v) : value(v) {}
    int getValue() const {
        return value; // This method does not modify any member
    }
};
```
### const with Objects
Declaring an object as const ensures that it cannot be modified after initialization. Only const methods can be called on const objects.

```cpp
const Example e(10);
int val = e.getValue(); // Valid
e.value = 20; // Error: Cannot modify const object
```
## friend with Classes and Functions
### friend Class
A friend class can access private and protected members of another class.

```cpp
class ClassB; // Forward declaration

class ClassA {
    friend class ClassB; // ClassB is a friend
private:
    int privateValue;
};

class ClassB {
public:
    void accessClassA(ClassA& a) {
        a.privateValue = 10; // Accessing private member
    }
};
```
### friend Function
A friend function can access private and protected members of the class in which it is declared as a friend.

```cpp
class Example {
    friend void display(const Example&); // Friend function
private:
    int value;
public:
    Example(int v) : value(v) {}
};

void display(const Example& e) {
    std::cout << "Value: " << e.value << std::endl; // Access private member
}
```
## static with Members and Methods
### static Members
Static members are shared across all instances of a class. They are not tied to a specific object and are accessible using the class name.

```cpp
class Example {
public:
    static int count;
    Example() {
        ++count;
    }
};

int Example::count = 0; // Definition and initialization of static member
```
### static Methods
Static methods can be called without an instance of the class. They can only access static members of the class.

```cpp
class Example {
public:
    static void showCount() {
        std::cout << "Count: " << count << std::endl;
    }
};
```
### static with const
Static const members are compile-time constants and can be initialized inside the class definition.

```cpp
class Example {
public:
    static const int maxValue = 100; // Static const member
};
```