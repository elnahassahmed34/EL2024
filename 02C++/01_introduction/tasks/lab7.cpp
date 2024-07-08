#include <iostream>
#include <string>
using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int decimal) {
    if (decimal == 0) {
        return "0";
    }
    
    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 1; // Represents 2^0 initially
    
    // Iterate binary string from right to left
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    
    return decimal;
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;
    
    string binary = decimalToBinary(number);
    cout << "Binary representation: " << binary << endl;
    
    cout << "Enter a binary number: ";
    cin >> binary;
    
    int decimal = binaryToDecimal(binary);
    cout << "Decimal representation: " << decimal << endl;
    
    return 0;
}
