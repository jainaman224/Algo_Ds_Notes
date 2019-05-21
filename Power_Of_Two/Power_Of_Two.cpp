/*
To check whether a number is a power of two or not,
we do bitwise "and" of number and number - 1, if the
result is zero the number is a power of two.
Example: number = 4, then 4 & 3 i.e 100 && 011 is 0
16 & 15 i.e 10000 & 01111 = 0
This is true for all powers of two.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}

int main()
{
    int num;
    cout<<"Enter a number to check:"<<endl;
    cin>>num;
    if (isPowerOfTwo(num))
        cout<<"The number is a power of two"<<endl;
    else
        cout<<"The number is not a power of two"<<endl;
    return 0;
}

/*
Input:
64

Output:
The number is a power of two

Input:
5

Output:
The number is not a power of two
*/
