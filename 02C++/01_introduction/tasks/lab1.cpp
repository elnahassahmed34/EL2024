#include <iostream>
using namespace std;

int main() {
    cout << "ASCII Code Table:" << endl;
    for (int i = 0; i <= 127; ++i) {
        cout << "ASCII value: " << i << ", Character: " << char(i) << endl;
    }
    return 0;
}
