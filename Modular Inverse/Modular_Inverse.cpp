/*
    Modular Inverse

    The task is to find the mod inverse of a number x, under the modulo of a given prime number.

    Modular inverse of a number x under modulo m, is defined as a number a(0<a<m), where 
    (a*x)%m = 1.
    When m is a prime number, according to Fermat's Little Theorem, (a^(m-1))%m = 1.
    On multiplying with a^(m-2) on both sides, (a^(-1))%m = (a^(m-2)).
*/
#include <bits/stdc++.h>
using namespace std;
#define lint long long int

lint modex(lint base, lint exponent, lint mod) {
    if (base == 0) {              // As, 0^x = 0, return 0;
        return 0;
    }
    if (exponent == 0) {          // As, x^0 = 1, return 1.
        return 1;
    }
    if (exponent % 2 == 0) {
        lint result = modex(base, exponent / 2, mod);   // We use the concept of (a^x)=((a^(x/2))*(a^(x/2)) when x is even, to reduce computation time effectively.
        return (result * result) % mod;
    }
    return ((base % mod) * modex(base, exponent - 1, mod)) % mod;      // In case of Odd exponent, we just decrement it by 1, so that it becomes even.
}

lint modInverse(lint base, lint mod){
    if (__gcd(base, mod) != 1) {         // When gcd of the number and mod is not 1, The modular inverse doesn't exist.
        return -1;
    }
    return modex(base, mod - 2, mod);   // modular inverse of base under mod = base^(mod-2)%mod.
}

int main()
{
    lint base;
    lint mod;
    cin >> base;
    cin >> mod;
    lint ans = modInverse(base,mod);
    if (ans == -1) {
        cout << "Modular Inverse of " << base << " under " << mod << " does not exist";
    }
    else {
        cout << "Modular Inverse of " << base << " under " << mod << " is " << ans;
    }
}     
/*
Input :  base = 10, mod = 7.
Output: Modular Inverse of 10 under 7 is 5
Verification : (modinverse * base)%mod = 1.
               (5*10)%7 = 50%7 = 1.

*/

