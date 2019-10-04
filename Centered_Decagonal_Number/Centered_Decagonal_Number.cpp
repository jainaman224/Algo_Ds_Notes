/*
    A centered decagonal number is a centered figurate number that represents
    a decagon with a dot in the center and all other dots surrounding the center
    dot in successive decagonal layers. 
    
    The centered decagonal number for n is given by the formula
    5n^2+5n+1 
*/

#include<iostream> 
using namespace std; 

// To calculate centered decagonal number 
int centeredDecagonal (int num) 
{ 
    // Using formula  
    return 5 * num * num + 5 * num + 1;  
} 

int main() 
{ 
    int num;
    cin>>num;
    cout<<num<<" centered decagonal number : "<<centeredDecagonal(num); 
    return 0; 
}

/*
Input:
6
output:
6 centered decagonal number : 211
*/
