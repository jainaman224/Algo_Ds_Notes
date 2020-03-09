//A number is called Automorphic number if and only if its square ends in the same digits as the number itself.

#include <iostream>
using namespace std; 

int main() 
{ 
    int num;
    cout << "Enter the number: ";
    cin >> num;
  
    // calculating the square of the number 
    int square = num * num; 
  
    // Start comparing digits 
    while (num > 0)
    { 
        // Return , if any digit of num doesn't 
        // match with its square's digits from last 
        if (num % 10 != square % 10) 
        {
            cout << "Not Automorphic";
            return 0;
        }   
         
        num /= 10; 
        square /= 10; 
    } 
    
    cout << "Automorphic";
    return 0; 
}

/*Enter the number: 25
Automorphic*/
