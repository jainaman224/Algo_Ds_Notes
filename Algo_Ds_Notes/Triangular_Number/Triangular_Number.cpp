/*The nth triangular number is the number of dots in the triangular arrangement 
with n dots on a side, and is equal to the sum of the n natural numbers from 1 to n.
We can check if a number is triangular number or not by solving a quadratic equation :
n^2 + n + (-2 * num) = 0 
where n is sum of first ‘n’ natural numbers
and num is the input number.
*/

#include <iostream>
#include <math.h>

using namespace std; 

int main() 
{ 
    int num;
    cout << "Enter a positive number: ";
    cin >> num;
    
    int a = 1, b = 1;
    int c = (num * -2); 
    
     // Calculating discriminant
    int d = (b * b) - (4 * a * c); 
  
    if (d < 0) 
    {
        cout << "The number is a triangular number";
        return 0; 
    }    
  
    // Calculating roots of equation 
    float root1 = ((-b) + sqrt(d)) / (2 * a); 
    float root2 = ((-b) - sqrt(d)) / (2 * a); 
  
    // if root1 is natural and integer number than it is a triangular number
    if (root1 > 0 && floor(root1) == root1) 
         cout << "The number is a triangular number"; 
  
    // if root2 is natural and integer number than it is a triangular number
    else if (root2 > 0 && floor(root2) == root2) 
        cout << "The number is a triangular number"; 
    else
        cout << "The number is not a triangular number";  
} 

/*Enter a positive number: 10
The number is a triangular number*/
