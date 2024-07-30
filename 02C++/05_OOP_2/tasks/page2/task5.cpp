#include <iostream>
#include <numeric> // for std::accumulate

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = std::accumulate(arr, arr + size, 0);

    std::cout << "Accumulate of array: " << sum << std::endl;

    return 0;
}
