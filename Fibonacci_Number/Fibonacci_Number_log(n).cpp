#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
The task is to find the nth fibonacci number, given n.
Here, we have used the following lemma:

|1 1|^n =   |F(n+1) F(n)  |
|1 0|   =   |F(n)   F(n-1)|

|. .|
|. .| denotes a matrix here, and F(n) denotes the nth fibonacci number ( F(1)=1, F(2)=1, F(3)=2, F(4)=3 and so on).
This lemma can be easily proven using mathematical induction.

To find the resultant matrix, we first implement matrix multiplication, and then find the nth power using
binary exponentiation.

The time complexity of this algorithm is O(log n).

All the 2x2 matrices have been implemented using a vector of vectors of integers.
*/

/*
Matrix multiplication has been implemented in the below function. It inputs two 2x2 matrices and returns their
resultant product (2x2). Time complexity is O(1).
*/
vector<vector<ll> > mmult(vector<vector<ll> > x, vector<vector<ll> > y){
    vector<vector<ll> > c;

    //Matrices are multiplied below and entries of resultant matrix is stored as integers.
    ll c00=x[0][0]*y[0][0]+x[0][1]*y[1][0];
    ll c01=x[0][0]*y[0][1]+x[0][1]*y[1][1];
    ll c10=x[1][0]*y[0][0]+x[1][1]*y[1][0];
    ll c11=x[1][0]*y[0][1]+x[1][1]*y[1][1];

    //First we make two vectors of integers and add the corresponding rows of the matrix to each vector.
    vector<ll> v,k;
    v.push_back(c00);
    v.push_back(c01);
    k.push_back(c10);
    k.push_back(c11);

    //Then we add these two vectors of integers to the matrix, i.e. the vector of vectors.
    c.push_back(v);
    c.push_back(k);

    return c;
}

/*
We calculate the matrix m^n for a given 2x2 matrix m and natural no. n.
We do this using binary exponentiation, i.e. recursively returning (m^(n/2))^2 when n is even,
and returning m*(m^(n-1)) when n is odd. Base case is n=0, where we return the identity matrix.
This works in O(log n) time.
*/
vector<vector<ll> > exp(vector<vector<ll> > m, ll n){
    //Base case
    if(n==0){
        vector<vector<ll> > id;
        //Making the identity matrix...
        vector<ll> v,k;
        v.push_back(1);
        v.push_back(0);
        k.push_back(0);
        k.push_back(1);
        id.push_back(v);
        id.push_back(k);
        return id;
    }
    else if(n%2==0){
        vector<vector<ll> > k=exp(m, n/2);
        return mmult(k, k);
    }
    else{
        vector<vector<ll> > k=exp(m, n-1);
        return mmult(m, k);
    }
}

int main(){
    ll n = 20;
    vector<vector<ll> > m;
    /*
    Initializing m = |1 1|
                     |1 0|
    */
    vector<ll> v,k;
    v.push_back(1);
    v.push_back(1);
    k.push_back(1);
    k.push_back(0);
    m.push_back(v);
    m.push_back(k);
    vector<vector<ll> > M=exp(m, n-1);
    cout<<M[0][0];
    return 0;
}
