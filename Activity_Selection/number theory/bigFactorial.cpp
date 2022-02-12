#define pb push_back
#define ll long long
#include <bits/stdc++.h>
using namespace std;


void multiply(int *a, int &n, int no) {

    int carry = 0;
    for (int i = 0; i < n; ++i) {
        int product = a[i] * no + carry;
        a[i] = product % 10;
        carry = product / 10;
    }

    while (carry) {
        a[n] = carry % 10;
        carry /= 10;
        n++;
    }
}
void big_factorial(int number) {

    int *a = new int[10000] {0};
    int n = 1;
    a[0] = 1;

    for (int i = 2; i <= number; i++) {
        multiply(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    big_factorial(1000);
    return 0;
}
