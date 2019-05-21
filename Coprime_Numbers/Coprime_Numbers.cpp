/*
Two integers a and b are said to be coprime if the only positive
integer that divides both of them is 1 i.e their greatest common 
divisor or GCD is 1.
Example: 5 and 7, as gcd(5, 7) = 1
9 and 11, as gcd(9, 11) = 1
*/

#include<bits/stdc++.h>
using namespace std;

int isCoprime(int a, int b)
{
    if(__gcd(a, b) == 1)
        return 1;
    return 0;    
}

int main()
{
    int a, b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    int ans = isCoprime(a, b);
    if(ans == 1)
        cout<<"The numbers are coprime"<<endl;
    else
        cout<<"The numbers are not coprime"<<endl;
    return 0;
}

/*
Input:
9
11

Output:
The numbers are coprime

Input:
4
12

Output:
The numbers are not coprime
*/
