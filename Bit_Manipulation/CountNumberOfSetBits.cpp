#include <iostream>
using namespace std;

int count(int n) {
    int mask = 1, count = 0;
    while(mask) {
        if(mask&n)
            count++;
        mask = mask<<1; // mask goes till least possible value (INT_MIN) then exits. (32-bit number)
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number to count set bits: ";
    cin >> n;
    cout << "Number of set bits in number " << n << " is " << count(n) << endl;
}
