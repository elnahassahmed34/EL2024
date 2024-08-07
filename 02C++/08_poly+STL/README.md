# Understanding Inheritance in C++

## Introduction
Inheritance is a fundamental concept in Object-Oriented Programming (OOP) that allows one class (derived class) to inherit attributes and methods from another class (base class). This promotes code reuse and establishes a natural hierarchy between classes. There are five main types of inheritance in C++:

1. Single Inheritance
2. Multiple Inheritance
3. Hierarchical Inheritance
4. Multilevel Inheritance
5. Hybrid Inheritance

## 1. Single Inheritance
Single inheritance involves a derived class inheriting from a single base class.

Example
```cpp
#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base class method" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() {
        std::cout << "Derived class method" << std::endl;
    }
};

int main() {
    Derived obj;
    obj.show();    // Base class method
    obj.display(); // Derived class method
    return 0;
}
```
## 2. Multiple Inheritance
Multiple inheritance allows a derived class to inherit from more than one base class.

Example
```cpp
#include <iostream>

class Base1 {
public:
    void show() {
        std::cout << "Base1 class method" << std::endl;
    }
};

class Base2 {
public:
    void display() {
        std::cout << "Base2 class method" << std::endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    void print() {
        std::cout << "Derived class method" << std::endl;
    }
};

int main() {
    Derived obj;
    obj.show();    // Base1 class method
    obj.display(); // Base2 class method
    obj.print();   // Derived class method
    return 0;
}
```

## 3. Hierarchical Inheritance
Hierarchical inheritance involves multiple derived classes inheriting from a single base class.

Example
```cpp
#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base class method" << std::endl;
    }
};

class Derived1 : public Base {
public:
    void display1() {
        std::cout << "Derived1 class method" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void display2() {
        std::cout << "Derived2 class method" << std::endl;
    }
};

int main() {
    Derived1 obj1;
    Derived2 obj2;
    obj1.show();     // Base class method
    obj1.display1(); // Derived1 class method
    obj2.show();     // Base class method
    obj2.display2(); // Derived2 class method
    return 0;
}
```
## 4. Multilevel Inheritance
Multilevel inheritance involves a derived class inheriting from another derived class.

Example
```cpp
#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base class method" << std::endl;
    }
};

class Intermediate : public Base {
public:
    void display() {
        std::cout << "Intermediate class method" << std::endl;
    }
};

class Derived : public Intermediate {
public:
    void print() {
        std::cout << "Derived class method" << std::endl;
    }
};

int main() {
    Derived obj;
    obj.show();     // Base class method
    obj.display();  // Intermediate class method
    obj.print();    // Derived class method
    return 0;
}
```
## 5. Hybrid Inheritance
Hybrid inheritance is a combination of two or more types of inheritance. It typically involves a mix of hierarchical, multiple, and multilevel inheritance.

Example
```cpp
#include <iostream>

class Base1 {
public:
    void show() {
        std::cout << "Base1 class method" << std::endl;
    }
};

class Base2 {
public:
    void display() {
        std::cout << "Base2 class method" << std::endl;
    }
};

class Intermediate : public Base1 {
public:
    void print() {
        std::cout << "Intermediate class method" << std::endl;
    }
};

class Derived : public Intermediate, public Base2 {
public:
    void message() {
        std::cout << "Derived class method" << std::endl;
    }
};

int main() {
    Derived obj;
    obj.show();    // Base1 class method
    obj.display(); // Base2 class method
    obj.print();   // Intermediate class method
    obj.message(); // Derived class method
    return 0;
}
```
