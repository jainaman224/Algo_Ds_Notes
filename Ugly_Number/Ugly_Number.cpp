//Ugly numbers are numbers whose only prime factors are 2, 3 or 5.

#include <bits/stdc++.h> 
#include <stdbool.h>
using namespace std; 
  
int main()
{
    int num;
    bool x = false;
 
    cout<<"Input an integer number: ";
    cin>>num;

    while (num != 1) 
    {  
        if (num % 5 == 0) //To check if number is divisible by 5 or not
        {  
            num /= 5;  
        } 
        else if (num % 3 == 0) //To check if number is divisible by 3 or not
        {  
            num /= 3;  
        } 
        else if (num % 2 == 0) //To check if number is divisible by 2 or not
        {  
            num /= 2;  
        } 
        else 
        {  
            cout<<"It is not an ugly number.\n"; 
            x = true;  
            break;  
        }  
    } 
    if ( !x )
    { 
        cout<<"It is an ugly number.\n";
    }
    return 0;
}
/*Input an integer number: 8
It is an ugly number.*/
