## Maps
### Maps
std::map<Key, T> is a sorted associative container that stores key-value pairs. The keys are unique and sorted based on their comparison function.
Example:

```cpp
#include <map>
#include <iostream>

std::map<int, std::string> myMap;
myMap[1] = "Apple";
myMap[2] = "Banana";
myMap[3] = "Cherry";

for(const auto& [key, value] : myMap) {
    std::cout << key << ": " << value << std::endl;
}
```
### Multimap
std::multimap<Key, T> is similar to std::map, but it allows multiple elements with the same key.
Example:

```cpp
#include <map>
#include <iostream>

std::multimap<int, std::string> myMultimap;
myMultimap.insert({1, "Apple"});
myMultimap.insert({1, "Apricot"});
myMultimap.insert({2, "Banana"});

for(const auto& [key, value] : myMultimap) {
    std::cout << key << ": " << value << std::endl;
}
```
### Unordered Map
std::unordered_map<Key, T> is an unordered associative container that stores key-value pairs. The keys are unique, and the order is not guaranteed.
Example:

```cpp
#include <unordered_map>
#include <iostream>

std::unordered_map<int, std::string> myUnorderedMap;
myUnorderedMap[1] = "Apple";
myUnorderedMap[2] = "Banana";
myUnorderedMap[3] = "Cherry";

for(const auto& [key, value] : myUnorderedMap) {
    std::cout << key << ": " << value << std::endl;
}
```
## Algorithms
### Existence Queries
- std::all_of, std::any_of, std::none_of
- std::all_of: Checks if all elements in a range satisfy a condition.
- std::any_of: Checks if any element in a range satisfies a condition.
- std::none_of: Checks if none of the elements in a range satisfy a condition.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4, 5};

bool allPositive = std::all_of(nums.begin(), nums.end(), [](int n){ return n > 0; });
bool anyNegative = std::any_of(nums.begin(), nums.end(), [](int n){ return n < 0; });
bool noneNegative = std::none_of(nums.begin(), nums.end(), [](int n){ return n < 0; });

std::cout << "All positive: " << allPositive << std::endl;
std::cout << "Any negative: " << anyNegative << std::endl;
std::cout << "None negative: " << noneNegative << std::endl;
std::count, std::count_if
std::count: Counts the number of elements in a range that are equal to a specified value.
std::count_if: Counts the number of elements in a range that satisfy a condition.
```
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4, 2, 2};

int countTwos = std::count(nums.begin(), nums.end(), 2);
int countEvens = std::count_if(nums.begin(), nums.end(), [](int n){ return n % 2 == 0; });

std::cout << "Count of 2s: " << countTwos << std::endl;
std::cout << "Count of even numbers: " << countEvens << std::endl;
std::mismatch
```
### Finds the first position where two ranges differ.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums1 = {1, 2, 3, 4};
std::vector<int> nums2 = {1, 2, 4, 4};

auto [mismatch1, mismatch2] = std::mismatch(nums1.begin(), nums1.end(), nums2.begin());

if (mismatch1 != nums1.end()) {
    std::cout << "First mismatch at position: " << (mismatch1 - nums1.begin()) << std::endl;
}
```
### Finding/Locating Elements
std::find
Searches for the first occurrence of an element in a range.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4, 5};

auto it = std::find(nums.begin(), nums.end(), 3);
if (it != nums.end()) {
    std::cout << "Found 3 at position: " << (it - nums.begin()) << std::endl;
}
```
### Comparing Ranges
- std::equal
- Checks if two ranges are equal.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums1 = {1, 2, 3, 4};
std::vector<int> nums2 = {1, 2, 3, 4};

bool areEqual = std::equal(nums1.begin(), nums1.end(), nums2.begin());
std::cout << "Ranges are equal: " << areEqual << std::endl;
```
### Max/Min
- std::min_element, std::max_element
- Finds the minimum or maximum element in a range.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4, 5};

auto minIt = std::min_element(nums.begin(), nums.end());
auto maxIt = std::max_element(nums.begin(), nums.end());

std::cout << "Min element: " << *minIt << std::endl;
std::cout << "Max element: " << *maxIt << std::endl;
```
### Sorted Range Algorithms
- std::binary_search

Checks if an element exists in a sorted range.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4, 5};
bool exists = std::binary_search(nums.begin(), nums.end(), 3);

std::cout << "Element 3 exists: " << exists << std::endl;
std::upper_bound
```
- Finds the first position where an element greater than a given value can be inserted to maintain sorted order.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 2, 3, 4};
auto upper = std::upper_bound(nums.begin(), nums.end(), 2);

std::cout << "Upper bound for 2: " << (upper - nums.begin()) << std::endl;
std::includes
```
Checks if one sorted range contains another sorted range.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums1 = {1, 2, 3, 4};
std::vector<int> nums2 = {2, 3};

bool contains = std::includes(nums1.begin(), nums1.end(), nums2.begin(), nums2.end());
std::cout << "nums1 contains nums2: " << contains << std::endl;
```
### Iterator Range
#### Transform
std::transform
Applies a function to a range and stores the result in another range.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4};
std::vector<int> squares(nums.size());

std::transform(nums.begin(), nums.end(), squares.begin(), [](int n) { return n * n; });

for (int square : squares) {
    std::cout << square << " ";
}
```
### ForEach
std::for_each
Applies a function to each element in a range.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4};

std::for_each(nums.begin(), nums.end(), [](int &n){ n *= 2; });

for (int num : nums) {
    std::cout << num << " ";
}
```
### Copy, Remove, and Accumulate
std::copy
Copies elements from one range to another.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4};
std::vector<int> copy(nums.size());

std::copy(nums.begin(), nums.end(), copy.begin());

for (int num : copy) {
    std::cout << num << " ";
}
```
### std::remove
Removes elements equal to a value and returns a new end iterator.
Example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 2, 3, 4};
auto newEnd = std::remove(nums.begin(), nums.end(), 2);

nums.erase(newEnd, nums.end());

for (int num : nums) {
    std::cout << num << " ";
}
```
### std::accumulate
Sums up elements in a range.
Example:

```cpp
#include <numeric>
#include <vector>
#include <iostream>

std::vector<int> nums = {1, 2, 3, 4};

int sum = std::accumulate(nums.begin(), nums.end(), 0);
std::cout << "Sum: " << sum << std::endl;
```
#### std::iota
- Fills a range with sequentially increasing values.
Example:
```cpp
#include <numeric>
#include <vector>
#include <iostream>

std::vector<int> nums(5);
std::iota(nums.begin(), nums.end(), 1); // Fills with 1, 2, 3, 4, 5

for (int num : nums) {
    std::cout << num << " ";
}
```
