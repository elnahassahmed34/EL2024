# C++ Inheritance, Polymorphism, Abstract Classes, Dynamic Casting, and String Class

## 1. Inheritance Types: Public, Protected, Private
Inheritance is one of the fundamental features of Object-Oriented Programming (OOP) in C++. It allows one class to inherit properties and behaviors (data members and member functions) from another class.

- Public Inheritance: The public and protected members of the base class remain public and protected in the derived class.
- Protected Inheritance: The public and protected members of the base class become protected in the derived class.
- Private Inheritance: The public and protected members of the base class become private in the derived class.
```cpp
#include <iostream>

class Base {
public:
    int publicVar = 1;
protected:
    int protectedVar = 2;
private:
    int privateVar = 3;
};

// Public Inheritance
class DerivedPublic : public Base {
public:
    void display() {
        std::cout << "PublicVar: " << publicVar << std::endl;
        std::cout << "ProtectedVar: " << protectedVar << std::endl;
        // std::cout << "PrivateVar: " << privateVar << std::endl; // Error: privateVar is not accessible
    }
};

// Protected Inheritance
class DerivedProtected : protected Base {
public:
    void display() {
        std::cout << "PublicVar: " << publicVar << std::endl;
        std::cout << "ProtectedVar: " << protectedVar << std::endl;
    }
};

// Private Inheritance
class DerivedPrivate : private Base {
public:
    void display() {
        std::cout << "PublicVar: " << publicVar << std::endl;
        std::cout << "ProtectedVar: " << protectedVar << std::endl;
    }
};

int main() {
    DerivedPublic objPublic;
    objPublic.display();
    
    DerivedProtected objProtected;
    objProtected.display();

    DerivedPrivate objPrivate;
    objPrivate.display();

    return 0;
}
```

## 2. Polymorphism: virtual Keyword and vtable
Polymorphism allows one interface to be used for a general class of actions. The specific action is determined by the exact nature of the situation.

- Virtual Function: A function declared as virtual in a base class allows derived classes to override it.
- vtable: A table of function pointers used to implement runtime polymorphism.
Example Code
```cpp
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show() function." << std::endl;
    }

    void display() {
        std::cout << "Base class display() function." << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show() function." << std::endl;
    }

    void display() {
        std::cout << "Derived class display() function." << std::endl;
    }
};

int main() {
    Base *bPtr;
    Derived d;
    bPtr = &d;

    bPtr->show();    // Calls Derived class show() function (Runtime polymorphism)
    bPtr->display(); // Calls Base class display() function (Compile-time binding)

    return 0;
}
```

## 3. Abstract Class (Interface) and Pure Virtual Function
An abstract class is a class that cannot be instantiated and often contains at least one pure virtual function. A pure virtual function is declared by assigning 0 to it.

Example Code
```cpp
#include <iostream>

class AbstractBase {
public:
    virtual void pureVirtualFunc() = 0; // Pure virtual function
    void concreteFunc() {
        std::cout << "This is a concrete function." << std::endl;
    }
};

class Derived : public AbstractBase {
public:
    void pureVirtualFunc() override {
        std::cout << "Implementation of pure virtual function in Derived class." << std::endl;
    }
};

int main() {
    Derived d;
    d.pureVirtualFunc();
    d.concreteFunc();

    return 0;
}
```

## 4. Dynamic Casting
Dynamic casting is used for safe downcasting at runtime. It is primarily used in situations involving polymorphism, where you need to determine the actual derived type of an object referenced by a base class pointer/reference.

Example Code
```cpp
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show() function." << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show() function." << std::endl;
    }

    void derivedOnlyFunc() {
        std::cout << "Derived class specific function." << std::endl;
    }
};

int main() {
    Base *bPtr = new Derived;

    // Attempt to cast to Derived
    Derived *dPtr = dynamic_cast<Derived*>(bPtr);
    if (dPtr) {
        dPtr->derivedOnlyFunc();
    } else {
        std::cout << "Dynamic cast failed." << std::endl;
    }

    delete bPtr;
    return 0;
}
```

## 5. String Class
The std::string class in C++ is a part of the Standard Library that provides a variety of functions for string manipulation.

### Constructors
- string(): Default constructor.
- string(const char* s): Constructs a string from a C-string.
- string(const string& str): Copy constructor.

Example Code
```cpp
#include <iostream>
#include <string>

int main() {
    std::string str1; // Default constructor
    std::string str2("Hello, World!"); // Constructor from C-string
    std::string str3(str2); // Copy constructor

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    return 0;
}
```
### Common Functions
- size(): Returns the size of the string.
- append(const string& str): Appends a string to the end.
- substr(size_t pos = 0, size_t len = npos): Returns a substring.
- find(const string& str): Finds the first occurrence of a substring.

Example Code
```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::cout << "Size of str: " << str.size() << std::endl;

    str.append(" C++");
    std::cout << "After append: " << str << std::endl;

    std::string subStr = str.substr(7, 5);
    std::cout << "Substring: " << subStr << std::endl;

    size_t pos = str.find("World");
    if (pos != std::string::npos) {
        std::cout << "Found 'World' at position: " << pos << std::endl;
    }

    return 0;
}

```
