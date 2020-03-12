/*
        ARITHMETIC PROGRESSION

        Any sequence of elements where the difference between any two 
        consecutive elements is equal is termed to be in A.P.
        The nth term of an A.P. is defined as (a + (n - 1)*d)
        where a is the first element of the A.P.
        d is the common difference of the A.P.
*/

using System;

class ArithmeticProgression
{
    public static void Main() {
        Console.WriteLine("Enter first number: ");
        int a = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Enter common difference: ");
        int d = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Enter number of terms: ");
        int n = Convert.ToInt32(Console.ReadLine());
        
        for(int i = 0; i < n; i++){
            Console.Write(a);
            Console.Write(" ");
            a += d;
        }
    }
}
/*
    INPUT : a = 5
            d = 2
            n = 7
    OUTPUT : The term at index 7 is 17
             Sum is: 77
    VERIFICATION : The A.P. would be 5,7,9,11,13,15,17...
*/