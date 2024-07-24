#include <iostream>
#include <algorithm>
#include <vector>

// Function to find the maximum number in an array
int findMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

// Function to search for a number in the array
bool searchNumber(const std::vector<int>& arr, int number) {
    for (int num : arr) {
        if (num == number) {
            return true;
        }
    }
    return false;
}

// Function to delete a number in the array
void deleteNumber(std::vector<int>& arr, int number) {
    arr.erase(std::remove(arr.begin(), arr.end(), number), arr.end());
}

// Function to merge two arrays together
std::vector<int> mergeArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged = arr1;
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    return merged;
}

// Function to find the even and odd numbers in the array
void findEvenAndOdd(const std::vector<int>& arr, std::vector<int>& evens, std::vector<int>& odds) {
    for (int num : arr) {
        if (num % 2 == 0) {
            evens.push_back(num);
        } else {
            odds.push_back(num);
        }
    }
}

// Simple Lambda: Calculate the square of a given number
auto square = [](int x) { return x * x; };

// Sort with Lambda: Sort an array of integers in ascending and descending order
void sortArray(std::vector<int>& arr, bool ascending = true) {
    std::sort(arr.begin(), arr.end(), [ascending](int a, int b) {
        return ascending ? a < b : a > b;
    });
}

int main() {
    std::vector<int> arr = {1, 5, 3, 4, 2};

    // Find the maximum number
    std::cout << "Max number: " << findMax(arr) << std::endl;

    // Search for a number
    int number = 3;
    std::cout << "Number " << number << (searchNumber(arr, number) ? " found" : " not found") << std::endl;

    // Delete a number
    deleteNumber(arr, 3);
    std::cout << "Array after deleting 3: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Merge two arrays
    std::vector<int> arr2 = {6, 7, 8};
    std::vector<int> merged = mergeArrays(arr, arr2);
    std::cout << "Merged array: ";
    for (int num : merged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Find even and odd numbers
    std::vector<int> evens, odds;
    findEvenAndOdd(merged, evens, odds);
    std::cout << "Even numbers: ";
    for (int num : evens) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Odd numbers: ";
    for (int num : odds) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Calculate the square using a lambda function
    int x = 4;
    std::cout << "Square of " << x << ": " << square(x) << std::endl;

    // Sort the array in ascending order
    sortArray(merged, true);
    std::cout << "Sorted array (ascending): ";
    for (int num : merged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the array in descending order
    sortArray(merged, false);
    std::cout << "Sorted array (descending): ";
    for (int num : merged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
