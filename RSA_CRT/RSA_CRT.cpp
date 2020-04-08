#include <bits/stdc++.h>
using namespace std;

// gcd function
long long int egcd (long long int a, long long int b) { 
    int rem;
    
    while (b != 0) {
        rem = a % b;
        a = b;
        b = rem;
        }
    return a;
}

// modular inversion function
long long int findInv (long long int x, long long int y, long long int n) {
    long long int d = 2, temp;

    while (d < n) {
        temp = ((d * x) - 1) % y;
        if (temp == 0)
        break;
        d ++;
    }
    return d;
}

// m is message to be encrypted, 1 < m < n 
int main() {
    long long int m, p, q, n, e, c, m1 = 1, m2 = 1, c11;
    long long int phi, dP, dQ, qInv, h, message;
    
    cout << "Enter the message \n";
    cin >> m;
    
    // p and q are two random prime numbers
    cout << "Enter two prime numbers";
    cin >> p;
    cin >> q;
    n = p * q;
    
    // eulers toitent function
    phi = (p - 1) * (q - 1);
    
    // (n, e) forms our public key , 1 < e < phi
    e = 2;
    while ( e < phi) {
        if (egcd (e, phi) == 1)
           break;
        e ++;
    }
    
    //calculating CRT exponents dP, dQ and qInv to make calculations shorter and faster
    dP = findInv (e , p - 1, n);
    dQ = findInv (e , q - 1 , n);
    qInv = findInv (q, p, n);
    
    //printing ciper text
    c11 = pow (m, e);
    c =  c11 % n;
    cout << "Cipher = " << c << "\n";
    
    //printing original message
    for (int i = 1; i <= dP; i++) {
        m1 = ( m1 * c) % p;
    }
    
    for(int i = 1; i <= dQ; i++) {
        m2 = (m2 * c) % q;
    }
    h = (qInv * (m1 + p - m2)) % p;
    message = m2 + (h * q);
    cout << "Orignal message = " << message << "\n";

    return 0;
}

/* 
Input :
Enter the message
1331
Enter two prime numbers
131
137
Output :
Cipher =  16990
Orignal Message =  1331
*/

