/*
    program to check for armstrong number.
    An Armstrong number is a number that is equal to the sum of digits raise to the power total number of digits in the number
*/

import 'dart:io';
import 'dart:math';

bool is_armstrong(int n,int l)
{
    int n1, rem, sum = 0; 
    n1 = n;
   
    while(n1 > 0)
    {
        rem = n1 % 10;
        sum = sum + pow(rem, l);
        n1 = (n1 / 10).toInt();
    }
    
    if(sum == n)
        return true;
    
    return false;
}

main()
{
    print("Enter a number  ");
    var input = stdin.readLineSync();
    
    int len = input.length;              //to clalculate the length of string
    int num = int.parse(input);         //conveting string into integer    
    
    bool check = is_armstrong(num, len);

    if(check == true)
        print("YES");
    else
        print("NO");
}

/*
Enter a number 407
YES
*/
