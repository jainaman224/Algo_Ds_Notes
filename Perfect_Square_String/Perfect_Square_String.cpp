/*Perfect Square String is a string in which sum of ASCII value of all characters is a perfect square.*/ 

#include<bits/stdc++.h> 
using namespace std; 
  
float perfectSquareString(string str) 
{ 
    int sum = 0; 
      
    // Length of the string 
    int length = str.length(); 
      
    // Calculating sum of the string by converting it in its ASCII value
    for (int i = 0; i < length; i++) 
        sum = sum + (int)str[i]; 
      
    // Calculating square root 
    long double squareRoot = sqrt(sum); 
      
    // Checking if square root is an integer 
    return squareRoot - floor(squareRoot); 
} 
  
// Driver code 
int main() 
{ 
    string str;
    cin>>str;
      
    if (perfectSquareString(str) == 0) 
        cout<<"YES"; 
    else
        cout<<"NO"; 
} 

/*
INPUT :
Q
OUTPUT :
YES
Becasue ASCII value of Q is 81 which is a perfect square
*/
