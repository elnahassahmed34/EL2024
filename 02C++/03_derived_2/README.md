# C++ Concepts
## Lambda Expressions
### Syntax
- Lambda expressions provide a concise way to create anonymous function objects. The basic syntax is:

```cpp
auto func = []() {
    // function body
};
```
- You can also capture variables, pass parameters, and specify the return type:

```cpp
auto func = [captured_variables](parameters) -> return_type {
    // function body
};
```
## Implementation (Functors)
Lambda expressions are essentially syntactic sugar for creating functors (objects that can be called as if they are functions). Here's an example of a lambda expression and its equivalent functor:

```cpp
// Lambda expression
auto lambda = [](int a, int b) -> int {
    return a + b;
};
// Equivalent functor
struct Add {
    int operator()(int a, int b) const {
        return a + b;
    }
};
```
- Both lambda and Add can be used to add two integers.

## Const vs Constexpr
### const
The const keyword is used to declare variables whose value cannot be changed after initialization. It can be used with variables, pointers, and member functions:

```cpp
const int x = 10;          // constant variable
const int* ptr = &x;       // pointer to a constant integer
int* const ptr2 = &x;      // constant pointer to an integer
```
### constexpr
The constexpr keyword is used to declare variables, functions, and objects that can be evaluated at compile time. This allows for optimizations and ensures that the value is constant:

```cpp
constexpr int y = 20;      // constant expression

constexpr int add(int a, int b) {
    return a + b;
}

constexpr int result = add(3, 4); // evaluated at compile time
```

### Differences
- const ensures that the value cannot be changed, but the value might be determined at runtime.
- constexpr ensures that the value is constant and can be evaluated at compile time.
```cpp
const int a = 5;
constexpr int b = 10;

int array1[a];           // This may not compile, depending on the compiler
int array2[b];           // This will always compile

constexpr int add(int x, int y) {
    return x + y;
}

int result = add(a, b);  // This will be evaluated at compile time
```

tasks:
