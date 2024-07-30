#include <iostream>
#include <stack>
#include <string>

// FunctionTracer Class
class FunctionTracer {
public:
    // Enter a function and log its name
    static void enterFunction(const std::string& funcName) {
        callStack.push(funcName);
        std::cout << "Enter to " << funcName << std::endl;
    }

    // Exit a function and log its name
    static void exitFunction() {
        if (!callStack.empty()) {
            std::string funcName = callStack.top();
            callStack.pop();
            std::cout << "Exit from " << funcName << std::endl;
        }
    }

    // Print the current backtrace of function calls
    static void printBacktrace() {
        std::cout << "\nBacktrace as follows:" << std::endl;
        std::stack<std::string> tempStack = callStack;
        int level = 0;
        while (!tempStack.empty()) {
            std::cout << level++ << " - " << tempStack.top() << std::endl;
            tempStack.pop();
        }
        std::cout << "Backtrace is finished\n" << std::endl;
    }

private:
    static std::stack<std::string> callStack; // Stack to store function call history
};

// Initialize the static call stack
std::stack<std::string> FunctionTracer::callStack;

// Functions with tracing
void func3() {
    FunctionTracer::enterFunction("func3");
    try {
        // Function logic (add your code here)
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw;
    }
    FunctionTracer::exitFunction();
}

void func2() {
    FunctionTracer::enterFunction("func2");
    try {
        func3();
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw;
    }
    FunctionTracer::exitFunction();
}

void func1() {
    FunctionTracer::enterFunction("func1");
    try {
        func2();
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw;
    }
    FunctionTracer::exitFunction();
}

int main() {
    FunctionTracer::enterFunction("main");
    try {
        func1();
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw;
    }
    FunctionTracer::exitFunction();

    return 0;
}
