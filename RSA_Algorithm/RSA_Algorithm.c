#include <stdio.h>
#include <math.h>

// gcd function
int egcd(int a, int b) 
{
    int rem;
    while(b != 0) {
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main() 
{
    // m is message to be encrypted, 1 < m < n
    int m, p, q, phi, e, d, temp, n, c, message;

    printf("Enter numeric text message : ");
    scanf("%d", &m);

    // p & q are two random prime numbers
    p = 5;
    q = 7;
    n = p * q;

    // eulers toitent function
    phi = (p - 1) * (q - 1);

    //(n,e) forms our public key, 1 < e < phi
    e = 2;
    while(e < phi) {
        if (egcd(e, phi) == 1)
            break;
        e ++;
    }
    // (n,d) forms our private key, 1 < d < phi
    d = 2;
    while (d < phi){
        temp = fmod(((e * d) - 1), phi);
        if (temp == 0)
            break;
        d ++;
    }

    // printing cipher text 
    c = fmod(pow(m, e), n);
    printf("Cipher = %d\n", c);

    // printing original message
    message = fmod(pow(c, d), n);
    printf("Message = %d\n", message);

    return 0;
}

/*
Input :
Enter numeric text message : 19
Output :
Cipher = 24
Message = 19
*/
