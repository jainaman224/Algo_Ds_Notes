/*Perfect Square String is a string in which sum of ASCII value of all characters is a perfect square.*/ 

#include<stdio.h> 
#include<string.h>
#include<math.h>

float perfectSquareString(char str[]) 
{ 
    int sum = 0; 
      
    // Length of the string 
    int length = strlen(str);
          
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
    char str[10];
    scanf("%s", &str);
      
    if (perfectSquareString(str) == 0) 
        printf("YES"); 
    else
        printf("NO"); 
}

/*
INPUT :
Q
OUTPUT :
YES
Becasue ASCII value of Q is 81 which is a perfect square
*/
