//C++ Program to find last digit of square of nth fibonacci numbers
#include<iostream>
using namespace std;

int main(){
    int a[60], n, i, c, b[60], j;
    a[0] = 0;
    a[1] = 1;
    b[0] = 0;
    b[1] = 1;
    //Using the concept that after 60 numbers in a fibonacci numbers the last digit repeats itself again and again
    for(i = 2 ; i < 60 ; i++ ){        //for storing the last digits of squares of first 60 fibonacci numbers
        a[i] = (a[i-1] + a[i-2]) % 10;       
        c = a[i];                        
        b[i] = (c * c) % 10;            //Now we will store last digits in new array and their index as position in fibonacci series 
    } 
    cin>> n ;  

    cout<< "\nThe Position of Fibonacci Number: " << n ; //getting the required number
    
    cout<< "\nThe Last Digit of Square of this Number : " << b[n % 60] ;//print the last digit given in that position
    return 0;
}
/*
Sample Input 1:
2344
Sample Output 1:
The Position of Fibonacci Number: 2344
The Last Digit of Square of this Number : 9
Sample Input 2:
267
Sample Output 2:
The Position of Fibonacci Number : 267
The Last Digit of Square of this Number : 4
*/
