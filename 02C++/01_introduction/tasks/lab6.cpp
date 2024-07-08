#include <iostream>
using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    
    int sum = sumOfDigits(abs(number));
    cout << "Sum of digits of " << number << " is: " << sum << endl;
    
    return 0;
}
