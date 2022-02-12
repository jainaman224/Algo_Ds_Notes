#define pb push_back
#define ll long long

#include <bits/stdc++.h>
using namespace std;

/*
    1.
       1.1 if the given power is odd than multiply it with result and reduce 1.
       i.e. res       base     power
            1           2        13
            2           2        12
       1.2 else double the base and half the power.
            2           4        6
            2           16       3
            32          16       2
            32          256      1
--->final   8192        256      0
answer

    2.repeat 1. untill power becomes zero.
    bruteforce: O(n)
    timecomplexity: O(logn)
*/

int power(int base, int n) {
    int res = 1;
    while (n) {
        if (n % 2 != 0) {
            res *= base;
            n--;
        } else {
            base *= base;
            n /= 2;
        }
    }

    return res;
}

int power(int base, int n, int m) {
    int res = 1;
    while (n) {
        if (n % 2 != 0) {
            res = (res * base) % m;
            n--;
        } else {
            base = (base * base) % m;
            n /= 2;
        }
    }

    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int base, n;
    cin >> base >> n;


    cout << power(2, 2) << endl;
    return 0;
}
