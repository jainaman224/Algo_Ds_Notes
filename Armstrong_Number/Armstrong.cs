using System;  
  public class Armstrong
   {  
     public static void Main(string[] args)  
      {  
       int  n,r,sum=0,temp;      
       Console.Write("Enter the Number= ");      
       n= int.Parse(Console.ReadLine());     
       temp=n;      
       while(n>0)      
       {      
        r=n%10;      
        sum=sum+(r*r*r);      
        n=n/10;      
       }      
       if(temp==sum)      
        Console.Write("The Entered Number is an Armstrong Number.");      
       else      
        Console.Write("The Entered number is not an Armstrong Number.");      
      }  
  }  
//Sample inputs and outputs:

//Enter the Number= 153
//The Entered Number is an Armstrong Number.

//Enter the Number= 121
//The Entered number is not an Armstrong Number.
