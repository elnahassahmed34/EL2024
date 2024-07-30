#include <iostream>
#include <vector>

bool areAllEven(const std::vector<int>& arr) {
    for (int num : arr) {
        if (num % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8, 10};

    if (areAllEven(arr)) {
        std::cout << "All elements in the array are even." << std::endl;
    } else {
        std::cout << "Not all elements in the array are even." << std::endl;
    }

    return 0;
}
