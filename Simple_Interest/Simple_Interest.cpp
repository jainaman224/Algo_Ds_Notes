/*
SIMPLE INTEREST

Simple Interest in Accounting is calculated as :

S.I. = (p * r * t) / 100
where p = principal amount
      r = rate of interest
      t = time
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    float p, r, t;
    cout<<"Enter Principal: ";
    cin>>p;
    cout<<"Enter Rate: ";
    cin>>r;
    cout<<"Enter Time: ";
    cin>>t;
    cout<<"Simple Interest is: "<<((p * r * t) / 100);
}

/*
INPUT : p = 1000, r = 8, t = 2
OUTPUT : Simple Interest is: 160.00
*/
