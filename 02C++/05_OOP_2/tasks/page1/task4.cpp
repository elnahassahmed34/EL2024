#include <iostream>
#include <cstring> // For strlen and strcpy

class String {
private:
    char* str;
    std::size_t length;

public:
    // Constructor
    String(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1]; // Allocate memory for the string
        std::strcpy(str, s); // Copy the string
    }

    // Copy constructor
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    // Move constructor
    String(String&& other) noexcept {
        str = other.str;
        length = other.length;
        other.str = nullptr; // Nullify the other string pointer
        other.length = 0;
    }

    // Destructor
    ~String() {
        delete[] str;
    }


    // Get the length of the string
    std::size_t getLength() const {
        return length;
    }

    // Get the string
    const char* getString() const {
        return str;
    }

    // Display the string
    void display() const {
        std::cout << "String: " << str << ", Length: " << length << std::endl;
    }
};

int main() {
    String s1("Hello, World!");
    s1.display();


    return 0;
}
