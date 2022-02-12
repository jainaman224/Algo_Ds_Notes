#include <bits/stdc++.h>
using namespace std;

//Implementing the Euclid's Algorithm to compute GCD (Greatest Common Divisor)
//If z= gcd(x,y) Then z is the largest number that can divide both x and y
//gcd(x,y) is equal to gcd(y, x%y) 
//gcd(x,0)=gcd(0,x) is x

int gcd(int x, int y){
 if(x<y){
    int temp= x;
    x=y;
    y=temp;
 }
 
 if(y==0)
 return x;
 
 if(x%y == 0)
 return y;
 else
 return gcd(y, x%y);

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);	
    int n1=0,n2=0;
    cout<<"Enter number 1: ";
    cin>>n1;
    cout<<"Enter number 2: ";
    cin>>n2;
    cout<<endl;
    
    if(n1==0 && n2==0 )
    cout<<"The GCD of 0 and 0 is Not Defined"<<endl;
    else
    cout<<"The GCD of "<<n1<<" and "<<n2<<" is: "<<gcd(n1,n2);
    
	return 0;
}