/**
 * @file main.c
 * @brief A simple example to demonstrate Doxygen usage.
 */

/**
 * @brief Adds two integers.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return Sum of the two integers.
 */
int add(int a, int b) {
    return a + b;
}

/**
 * @brief Subtracts the second integer from the first.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return Difference of the two integers.
 */
int subtract(int a, int b) {
    return a - b;
}

int main() {
    int result1 = add(3, 4);
    int result2 = subtract(7, 2);

    return 0;
}
