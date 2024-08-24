#include <iostream>
#include <cstring> // For strlen, strcpy
#include <cassert> // For assert

class MyString {
private:
    char* data std::endl;

public:
    // Default constructor
    MyString() : data(new char[1]{'\0'}) {}

    // Parameterized constructor
    MyString(const char* str) {
        size_t length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Copy constructor
    MyString(const MyString& other) {
        size_t length = std::strlen(other.data);
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            size_t length = std::strlen(other.data);
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Move assignment operator
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Concatenate
    MyString operator+(const MyString& other) const {
        size_t length1 = std::strlen(data);
        size_t length2 = std::strlen(other.data);
        char* newData = new char[length1 + length2 + 1];
        std::strcpy(newData, data);
        std::strcat(newData, other.data);
        MyString newString;
        newString.data = newData;
        return newString;
    }

    // Access element
    char& operator[](size_t index) {
        assert(index < std::strlen(data)); // Simple boundary check
        return data[index];
    }

    // Print string
    void print() const {
        std::cout << data;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2(" World");
    MyString s3 = s1 + s2;

    s3.print(); // Output: Hello World

    return 0;
}
