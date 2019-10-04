/*
Centered Square Number is a centered figurate number that gives the number
of dots in a square with a dot in the center and all other dots surrounding 
the center dot in successive square layers.
    
Nth Centered square number can be calculated by using formula n^2 + (n-1)^2.
*/

#include<iostream> 
using namespace std; 

int centeredSquare(int num) 
{ 
    // Using formula  
    return num * num + ((num - 1) * (num - 1)); 
} 
   
int main() 
{ 
    int num;
    cin>>num;
    cout<<centeredSquare(num); 
    return 0; 
}

/*
Input:
6
output:
61
*/
