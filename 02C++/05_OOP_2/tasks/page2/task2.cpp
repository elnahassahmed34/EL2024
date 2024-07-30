// The function f() returns a reference to a static integer x. Since x is static, it retains its value between calls. The main function assigns values to x through the reference returned by f().
#include <iostream>

int& f() {
    static int x = 0; 
    std::cout << "Current value of x: " << x << std::endl;
    return x;
}

int main() {

    f() = 10; // Sets static x to 10
    f();      // Prints 10
    f() = 0;  // Sets static x to 0
    f();      // Prints 0

    return 0;
}

// In this code, f() is first called and sets x to 10, then f() is called again, and x is printed, showing 10. Finally, f() is called, setting x to 0, and the last call to f() prints 0.