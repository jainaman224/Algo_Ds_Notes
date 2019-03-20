
#include <algorithm> 
#include <iostream>
#include <string>  

using namespace std; 
  
int min(int left, int right, int diagnol) 
{ 
   return min(min(left, right), diagnol); 
} 
  
int Edit_Distance(string first_str , string second_str , int size1 ,int size2) 
{ 
    // If first string is empty, insert all characters of second string into first 
    if (size1 == 0) return size2; 
  
    // If second string is empty, the only option is to remove all characters of first string 
    if (size2 == 0) return size1; 
  
    if (a[size1-1] == b[size2-1]) 
        return Edit_Distance(first_str, second_str, size1-1, size2-1); 
  
    /* If last characters are not same, consider all three operations on last character of first string, recursively 
     compute minimum cost for all three operations and take minimum of three values. 
     */
    return 1 + min ( Edit_Distance(first_str,  second_str, size1, size2-1),    // Insert 
                     Edit_Distance(first_str,  second_str, size1-1, size2),    // Resize1ove 
                     Edit_Distance(first_str,  second_str, size1-1, size2-1)  // Replace 
                   ); 
} 
  
// Driver program 
int main() 
{ 
    // input
    string a = "kanchan"; 
    string b = "thareja"; 
  
    cout << Edit_Distance( a , b , a.length(), b.length()); 
  
    return 0; 
} 


// OUTPUT : 

//   6

