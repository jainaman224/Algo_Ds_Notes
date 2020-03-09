/*
    The sum of squares of first N natural numbers is given
    by the equation ((N) * (N + 1) * (2 * N + 1)) / 6 i.e.
    1^2 + 2^2 + 3^2 + 4^2 + 5^2.........N^2 sums upto
    ((N) * (N + 1) * (2 * N + 1)) / 6
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cout<<"Enter the value of N: "<<endl;
    cin>>N;
    int ans = ((N) * (N + 1) * (2 * N + 1)) / 6;
    cout<<ans<<endl;
    return 0;
}

/*
Input:
N = 5

Output:
ans = 55

Verification:
1^2 + 2^2 + 3^2 + 4^2 + 5^2
= 1 + 4 + 9 + 16 + 25
= 55
*/
