#define pb push_back
#define ll long long

#include <bits/stdc++.h>
using namespace std;

int power(int a, int n) {
    if (n == 0) return 1; //Base condition
    if (n == 1) return a;

    int R = power(a, n / 2);  //divide the expression by 2

    /*
        a*a*a....a*a*a = b
         n/2       n/2
         R          R
         R*R = b  where n is even
        a*a*a. *a*..a*a*a = b
         n/2    a   n/2
         R      a    R
         R*a*R = b where n is odd
    */
    if (n % 2 == 0) {
        return R * R;
    }

    return R * R * a;
}

int power(int a, int n, int M) {
    if (n == 0) return 1; //Base condition
    if (n == 1) return a;

    if (n % 2 == 0) {
        return (power(a, n / 2) % M * power(a, n / 2) % M) % M;
    } else {
        return (power(a, n / 2) % M * power(a, n / 2) % M * a) % M;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << power(2, 8, 1e+7);
    return 0;
}
