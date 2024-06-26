# Follow up sessions

- doxygen task -> README.md
- gpio tasks -> 04_tasks -> avr_GPIO.py
- header file parse -> 04_tasks -> parse header

- explain private member 

## Private Members in Python and C++

```python
class MyClass:
    def __init__(self):
        self.__private_member = 42

    def get_private_member(self):
        return self.__private_member

    def __private_method(self):
        print("This is a private method.")

# Usage
obj = MyClass()
print(obj.get_private_member())  # 42
# print(obj.__private_member)  # AttributeError
# obj.__private_method()  # AttributeError

# Accessing private member through name mangling (not recommended)
print(obj._MyClass__private_member)  # 42
In this example:
```

```cpp
#include <iostream>

class MyClass {
private:
    int private_member;

    void private_method() {
        std::cout << "This is a private method." << std::endl;
    }

public:
    MyClass() : private_member(42) {}

    int getPrivateMember() const {
        return private_member;
    }
};

int main() {
    MyClass obj;
    std::cout << obj.getPrivateMember() << std::endl;  // 42
    // std::cout << obj.private_member << std::endl;  // Compilation error
    // obj.private_method();  // Compilation error
    return 0;
}
```

## Web scrapping -> 02_05_tasks -> scrapping 

## pyautogui 02_tasks -> locate
