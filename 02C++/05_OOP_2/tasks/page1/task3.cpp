#include <iostream>
#include <vector>

bool isAnyEven(const std::vector<int>& arr) {
    for (int num : arr) {
        if (num % 2 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9};

    if (isAnyEven(arr)) {
        std::cout << "There is at least one even number in the array." << std::endl;
    } else {
        std::cout << "There are no even numbers in the array." << std::endl;
    }

    return 0;
}
