#include<iostream>
#include<math.h>
using namespace std;
 
bool Prime (int num, int i) 
{ 
    if (num == 1)
        return false;

    // Base case
    if (i <= 1) 
        return true;

    // Checking if i is a divisor of num or not
    if (num % i == 0) 
        return false; 

    // Calling recursive function
    return Prime(num, i - 2); 
} 
// Driver Program 
int main() 
{ 
    int num;    
    cin >> num; 
    
    if (num == 2)
        cout << "It is a prime number";
    else if (num % 2 == 0)
        cout << "It is not a prime number";
    else
        if (Prime(num, sqrt(num))) 
            cout << "It is a prime number"; 
        else
            cout << "It is not a prime number";  
    return 0; 
} 

// Input: 29
// Output: It is a prime number
