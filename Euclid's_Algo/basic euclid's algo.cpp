C++ PROGRAM TO DEMONSTRATE BASIC EUCLIDEAN ALGORITHM

#include <iostream>
using namespace std;

int gcdfunction(int x,int y)  //recursive function
{  if(x==0)
    return y;
    else
    return gcdfunction(y%x, x);
}
   

int main() {
	int x,y;   //2 nos. whose gcd we've to find
	cin>>x>>y;
	cout<<"GCD of numbers "<<x<<" and "<<y<<" is \n"<<gcdfunction(x,y);
	return 0;
}

