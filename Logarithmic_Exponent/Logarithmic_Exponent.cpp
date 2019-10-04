#include <iostream>

using namespace std;

long long exponent (int base, int power) {
    long long result = 1, value = base;
    while (power) {
        if (power & 1)
            result *= value;
        value *= value;
        power /= 2;
    }
    return result;
}

int main () {
    int base, power;
    cin >> base;
    cin >> power;
    cout << "Value of " << base << " raised to the power " << power << " is " << exponent(base, power);
    return 0;
}

/*
Input:
base : 2, power : 32
Output:
Value of 2 raised to the power 32 is 4294967296
*/
