using System;
class Fibonacci
{
    static void Main(string[] args)
    {
       var input= int.Parse(Console.ReadLine()); //Takes Input 
        Console.WriteLine($"The fibonacci number at position {input} is {fibonaccinumber(input)}"); //print nth Fibonacci Number
        Console.Write("Fibonacci Series:    "); // print Fibonacci Series
        FibonacciSeries(input);
        Console.ReadLine();     
    }
    // Function to print fibonacci series
    static void FibonacciSeries(int input)
    {
        int x = 0, y = 1;
        if (input < 1)
            return;
        for (int i = 1; i <= input; i++)
        {
            Console.Write($"{y} ");
            int z = x + y;
            x = y;
            y = z;
        }
    }
    // Function to return nth fibonacci number
    static int fibonaccinumber(int input)
    {
        if (input <= 1)
            return input;

        return fibonaccinumber(input - 1) + fibonaccinumber(input - 2);
    }
}


/*

Input :

6

Output :

The fibonacci number at position 6 is 8

Fibonacci series:   1 1 2 3 5 8

*/
