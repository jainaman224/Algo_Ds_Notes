/*
    nCr % p.

    The task is to find the binomial coefficient nCr under modulo p. The normal approach would
    be to first find nCr and then do modulo p, which is highly inefficient for large numbers,
    and may cause overflow.
    Thus, we use dynamic programming approach to solve this problem as this is highly efficient over bruteforce approach.
*/
#include <bits/stdc++.h>
using namespace std;
#define lint long long int

lint nCr(lint n,lint r,lint mod){
    if(n<r){
        return -1;
    }
    // We create a pascal triangle.
    lint Pascal[r+1];
    Pascal[0]=1;
    for(lint i=1;i<=r;i++){
        Pascal[i]=0;
    }
    // We use the known formula nCr = (n-1)C(r) + (n-1)C(r-1) for computing the values.
    for(lint i=1;i<=n;i++){
        lint k = (i<r)?(i):(r); // we know, nCr = nC(n-r). Thus, at any point we only need min
        for(lint j=k;j>0;j--){ // of the two, so as to improve our computation time.
            Pascal[j] = (Pascal[j] + Pascal[j-1])%mod;
        }
    }
    return Pascal[r];
}

int main()
{
    lint n = 7;
    lint r = 5;
    lint mod = 6;
    lint ans = nCr(n,r,mod);
    if(ans == -1){
        cout<<"Bad Input. N can never be less than R.";
    }
    else{
        cout << "The value of nCr(" << n << "," << r << ")%" << mod << " is " <<ans ;
    }    
}     
/*
Input :  n = 7, r = 5, mod = 6.
Output: The value of nCr(7,5)%6 is 3
Verification : nCr(7,5) = 7!/((5!)(2!)) = 21
                21%6 = 3.

*/

