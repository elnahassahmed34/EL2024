#include <iostream>

int main() {
    const int size = 10000 - 10 + 1;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = 10 + i;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
