using System;
public class Armstrong
{
    public static void Main(string[] args)
    {
        // initialising variables
        int  n, r, sum = 0, temp;
        // asking for user input for the number to be checked
        Console.Write("Enter the Number = ");
        // storing the number in variable n
        n = int.Parse(Console.ReadLine());
        // storing the number in a temporary variable
        temp = n;
        // running while loop to get the condition number
        while(n > 0)      
        {
            r = n % 10;      
            sum = sum + (r * r * r);      
            n = n / 10;
        }
        // checking if the number found using the condition of finding armstrong number is equal to the given number
        // printing the statement according to the result of the condition
        if(temp == sum)
            Console.Write("The Entered Number is an Armstrong Number.");      
        else      
            Console.Write("The Entered number is not an Armstrong Number.");
    }
}

/*
Sample inputs and outputs:

Enter the Number = 153
The Entered Number is an Armstrong Number.

Enter the Number = 121
The Entered number is not an Armstrong Number.
*/
