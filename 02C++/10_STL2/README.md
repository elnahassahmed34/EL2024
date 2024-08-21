## 1. Raw Strings + Delimiter
Raw Strings:
Raw strings in C++ allow you to create strings that do not interpret backslashes (\) as escape characters or process any other special characters. This is useful when working with strings that contain many backslashes (like file paths or regular expressions).

```cpp
std::string rawString = R"(This is a raw string \n with no special character interpretation)";
```

### Delimiter:
You can specify a custom delimiter in raw strings to prevent confusion with characters inside the string.

```cpp
std::string customDelim = R"delimiter(This is a string with )delimiter) and () characters)delimiter";
```
## 2. std::getline() Function
Purpose:
std::getline() is used to read a line of text from an input stream (like std::cin or a file) into a string. It reads characters until a newline is encountered.

```cpp
std::getline(input_stream, string_variable);
```
Usage Example:
```cpp
std::ifstream file("example.txt");
std::string line;
while (std::getline(file, line)) {
    std::cout << line << std::endl;
}
```
## 3. STL (Standard Template Library)
### Containers:
Containers in STL store collections of objects. They include:

- Array: Fixed-size sequence of elements.
- Vector: Dynamic array, automatically resizes as elements are added.
- Deque: Double-ended queue, allows fast insertions/removals from both ends.
- List: Doubly linked list, allows fast insertions/removals at any position.
- Forward_list: Singly linked list, optimized for insertions and deletions at the front.
- Set: Collection of unique elements, ordered by value.
- Multiset: Like Set, but allows duplicate elements.
- Unordered_set: Collection of unique elements, not ordered.
- Map: Collection of key-value pairs, keys are unique and ordered.
- Unordered_map: Collection of key-value pairs, keys are unique but not ordered.
- Multimap: Like Map, but allows duplicate keys.

### Iterators:
Iterators are objects that point to elements within containers. They are used to traverse the elements.

### Algorithms:
STL provides many algorithms (e.g., sort, find, reverse, accumulate) to operate on containers using iterators.

## 4. Containers Overview
### Array:
- Fixed size.
- Fast access to elements via index.
Example:
```cpp
std::array<int, 5> arr = {1, 2, 3, 4, 5};
```

### Vector:
- Dynamic size.
- Efficient access via index and dynamic resizing.
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
vec.push_back(6);
```
### Deque:
- Fast insertions/removals from both ends.
- Random access like vectors.
Example:
```cpp
std::deque<int> deq = {1, 2, 3, 4, 5};
deq.push_front(0);
deq.push_back(6);
```
### List:
- Doubly linked list (bidirectional traversal).
- Efficient insertions/removals at any position.
Example:
```cpp
std::list<int> lst = {1, 2, 3, 4, 5};
lst.push_front(0);
lst.push_back(6);
```
### Forward_list:
- Singly linked list (only forward traversal).
- Optimized for insertions/removals at the front.
Example:
```cpp
std::forward_list<int> flst = {1, 2, 3, 4, 5};
flst.push_front(0);
```
### Set / Multiset / Unordered_set:
- Set: Stores unique elements in a specific order.
- Multiset: Allows duplicate elements, ordered.
- Unordered_set: Stores unique elements without any specific order, faster operations.
Example:
```cpp
std::set<int> mySet = {3, 1, 4, 1, 5}; // unique, sorted
std::unordered_set<int> myUnorderedSet = {3, 1, 4, 1, 5}; // unique, not sorted
std::multiset<int> myMultiSet = {3, 1, 4, 1, 5}; // allows duplicates, sorted
```
Source Code Examples
Raw Strings Example:
```cpp
#include <iostream>
#include <string>

int main() {
    std::string rawString = R"(C:\Users\Username\Documents)";
    std::cout << rawString << std::endl;
    return 0;
}
```
std::getline() Example:
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("example.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    return 0;
}
```
### STL Example with Vector:
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);

    for(int val : vec) {
        std::cout << val << " ";
    }
    return 0;
}
```
Set Example:
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {3, 1, 4, 1, 5};
    for (int val : mySet) {
        std::cout << val << " ";  // Output: 1 3 4 5
    }
    return 0;
}
```