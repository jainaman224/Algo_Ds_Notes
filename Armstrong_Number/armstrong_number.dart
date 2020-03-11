//armstorng number

import 'dart:io';
import 'dart:math';


bool is_armstrong(int n,int l)
{
    int n1,rem,sum=0; 
    n1=n;
    
    /*
        An Armstrong number is a number that is equal to the sum of digits raise to the power total number of digits in the number
    */

    while(n1>0)
    {
        rem=n1%10;
        sum=sum+pow(rem,l);
        n1=(n1/10).toInt();
        
    }
    if(sum==n)
        return true;
    
    return false;
}
main(){
    
    print("Enter a number  ");
    var input=stdin.readLineSync();
    
    var len=input.length;
    var num=int.parse(input);
    
    bool check=is_armstrong(num,len);
    
    if(check==true)
        print("YES");
    else
        print("NO");
    
}
