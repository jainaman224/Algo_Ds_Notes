#include <iostream> 
#include <stdbool.h>
using namespace std;    
  
/* Function to check if a number is ugly or not */
int isUgly(int num) 
{ 
    bool x = true;
    while (num != 1) 
    {  
        //To check if number is divisible by 5 or not
        if (num % 5 == 0) 
        {  
            num /= 5;  
        } 
        //To check if number is divisible by 3 or not
        else if (num % 3 == 0) 
        {  
            num /= 3;  
        }
        //To check if number is divisible by 2 or not
        else if (num % 2 == 0) 
        {  
            num /= 2;  
        } 
        else 
        {  
            x = false;  
            break;  
        }  
    }
    return x; 
}     

/* Function to get the nth ugly number*/
int NthUglyNumber(int n) 
{ 
    int i = 1;  
    int count = 1;   /* ugly number count */ 

    /*Check for all integers untill ugly count  becomes n*/ 
    while (n > count) 
    { 
        i++;       
        if (isUgly(i)) 
        count++;  
    } 
    return i; 
} 

int main() 
{ 
    int num;
    cout << "Enter the Nth number: ";
    cin >> num;
    int no = NthUglyNumber(num); 
    cout<< "\n" << num << "th ugly no. is " << no ; 

    return 0; 
}

/*
Enter the Nth number: 100
100th ugly no. is 1536*/
