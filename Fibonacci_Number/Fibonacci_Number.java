import java.util.Scanner;

class Fibonacci 
{ 
    // Function to print nth fibonacci number
    static int FibonacciNumber (int num) 
    { 
        if (num <= 1) 
            return num; 
        return FibonacciNumber(num - 1) + FibonacciNumber(num - 2); 
    } 
    
    // Function to print fibonacci series
    static void FibonacciSeries (int num)  
    {  
        int a = 0, b = 1, i;  

        if (num < 1)  
            return;  

        for (i = 1; i <= num; i++)  
        {  
            System.out.println(b + " ");  
            int c = a + b;  
            a = b;  
            b = c;  
        }  
    } 

    public static void main (String args[]) 
    { 
        int num; 
        Scanner s = new Scanner(System.in);
        num = s.nextInt();
        System.out.println("The fibonacci number at position " + num + "is " + FibonacciNumber(num));
        System.out.println("\nFibonacci series:\n");
        FibonacciSeries(num); 
    } 
}

/*
Input :
6
Output :
The fibonacci number at position 6 is 8
Fibonacci series:
1 1 2 3 5 8
*/
