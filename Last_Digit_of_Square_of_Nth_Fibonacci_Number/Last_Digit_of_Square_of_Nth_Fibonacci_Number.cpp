//C++ Program to find last digit of square of nth fibonacci numbers
#include<iostream>
using namespace std;

int main(){
    int a[60], n, i, c, b[60], j;
    a[0] = 0;
    a[1] = 1;
    b[0] = 0;
    b[1] = 1;
    
    /*Using the concept that after 60 numbers in a fibonacci 
    numbers the last digit repeats itself again and again*/
    
    /*In this loop we store the last digits of squares of first 60 fibonacci number and 
    we will store last digits in new array and their index as position in fibonacci series*/
    
    for(i = 2 ; i < 60 ; i++){  
        a[i] = (a[i - 1] + a[i - 2]) % 10;        
        c = a[i];                        
        b[i] = (c * c) % 10;            
    } 
    cin>> n ;
    
    //print the last digit given in that position
    
    cout<< " \n The Last Digit of Square of this Number : " << b[ n % 60] ;
    
    return 0;
}
/*
Sample Input 1:
2344

Sample Output 1:
The Last Digit of Square of this Number : 9

Sample Input 2:
267

Sample Output 2:
The Last Digit of Square of this Number : 4
*/
