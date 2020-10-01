#include<iostream> 
using namespace std;   
 
int main() 
{ 
    int num;
    cin>>num; 
  
    // To store octal number 
    int octal[100]; 
  
    int i = 0, j; 
    while (num != 0) 
    {   
        octal[i] = num % 8; 
        num = num / 8; 
        i++; 
    } 
  
    for (j = i - 1; j >= 0; j--) 
        cout<<octal[j];
  
    return 0; 
} 

/*
Input:
20
Output:
24
*/
