/*
    Compound Interest = P(1 + R/100)^T
    
    P is principle amount
    R is the rate and
    T is the time span
*/

#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
    float p, r, t;
    cout<<"Enter Principal: ";
    cin>>p;
    cout<<"Enter Rate: ";
    cin>>r;
    cout<<"Enter Time: ";
    cin>>t;
    cout<<p * (pow((1 + r / 100), t));
}

/*
INPUT : p = 1000, r = 8, t = 2
OUTPUT : Simple Interest is: 1166.4
*/
