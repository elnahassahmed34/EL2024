# C++ Concepts
## C++ is an Object-Oriented Programming (OOP) Language
- C++ is a multi-paradigm programming language that supports procedural, generic, and object-oriented programming styles. OOP is a programming paradigm based on the concept of "objects", which can contain data (attributes) and code (methods). The four pillars of OOP are encapsulation, inheritance, polymorphism, and abstraction.

## Initialization Types in C++
- In C++, there are several ways to initialize variables:

### Value Initialization:

- Initializes a variable to a known value.
- Example: int x{}; (x is initialized to 0).

### Direct Initialization:

- Calls the constructor directly.
- Example: int x(5); (x is initialized to 5).

### Copy Initialization:

- Initializes a variable using the value of another variable.
- Example: int x = 5; (x is initialized to 5).

### Uniform Initialization (C++11 and later):

- Uses curly braces {} for initializing variables.
- Prevents narrowing conversions.
- Example: int x{5}; (x is initialized to 5).

## Enum in C and C++ (enum class)
### C-Style Enum
- In C, enums are a way to assign names to integral constants, which makes the code more readable. However, they are not type-safe and can lead to naming conflicts.

```cpp
enum Color { RED, GREEN, BLUE };
Color color = RED;
```
### C++-Style Enum (enum class)
- C++ introduces enum class, which provides type safety and prevents naming conflicts. enum class members must be accessed using the scope resolution operator.

```cpp
enum class Color { RED, GREEN, BLUE };
Color color = Color::RED;
```
### Struct in C++
- A struct in C++ is a user-defined data type that groups together variables under a single name. Structs in C++ are similar to classes but differ mainly in terms of default access specifiers. In a struct, members are public by default.

```cpp
struct Point {
    int x;
    int y;
};
```

## Object-Oriented Programming (OOP)
### Class
- A class is a blueprint for creating objects (instances of the class). A class encapsulates data (attributes) and functions (methods) that operate on the data.

### Encapsulation
Encapsulation is the bundling of data and methods that operate on that data within a single unit or class, and restricting access to some of the object's components.

### Memory Layout
In C++, objects are typically allocated on the stack or the heap:

- Stack Segment: Local variables, including object instances, are stored here.
- Heap Segment: Dynamically allocated memory (using new and delete).
- Text Segment: Stores compiled code (the program's executable instructions).
- BSS Segment: Uninitialized global and static variables.

### Global Object and BSS Section
Global objects or static objects that are not explicitly initialized are placed in the BSS (Block Started by Symbol) segment of the memory, which is initialized to zero.

### Access Modifiers
- Public: Members are accessible from outside the class.
- Private: Members are only accessible from within the class itself.
- Protected: Members are accessible within the class and by derived class instances.

### Constructors
#### Default Constructor: A constructor that takes no arguments.

```cpp
class MyClass {
public:
    MyClass() {}  // Default constructor
};
```
#### Parameterized Constructor: A constructor that takes one or more arguments.

```cpp
class MyClass {
public:
    MyClass(int value) {}  // Parameterized constructor
};
```
### This Pointer
this is an implicit pointer in C++ that points to the object for which a member function is called. It is used within a class's member functions to refer to the invoking object.

```cpp
class MyClass {
    int value;
public:
    void setValue(int value) {
        this->value = value;
    }
};
```