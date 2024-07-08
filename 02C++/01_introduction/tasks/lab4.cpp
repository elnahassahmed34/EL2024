#include <iostream>
using namespace std;

bool isVowel(char letter) {
    switch (tolower(letter)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int main() {
    char ch;
    cout << "Enter a letter: ";
    cin >> ch;
    
    if (isalpha(ch)) {
        if (isVowel(ch)) {
            cout << ch << " is a vowel." << endl;
        } else {
            cout << ch << " is not a vowel." << endl;
        }
    } else {
        cout << "Invalid input! Please enter a letter." << endl;
    }
    
    return 0;
}
