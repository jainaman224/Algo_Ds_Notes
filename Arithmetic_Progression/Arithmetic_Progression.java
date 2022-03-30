/*
        ARITHMETIC PROGRESSION

        Any sequence of elements where the difference between any two 
        consecutive elements is equal is termed to be in A.P.
        The nth term of an A.P. is defined as (a + (n - 1)*d)
        where a is the first element of the A.P.
        d is the common difference of the A.P.
*/

import java.util.Scanner;

class Arithmetic_Progression {    
    static int SumOfAP(int a, int d, int n) { 
        // int sum = 0; 
        // for (int i = 0; i < n; i++) 
        // { 
        //     sum = sum + a; 
        //     a = a + d; 
        // } 
        // return sum; 
        return (n/2)*(2*a+((n-1)*d));
    } 
    
    public static void main(String args[]) {
        System.out.print("Enter the First Term of A.P.");
        int a;
        Scanner s = new Scanner(System.in);
        a = s.nextInt();
        System.out.print("Enter the common difference");
        int d;
        d = s.nextInt();
        System.out.print("Enter N (The index of term to find)");
        int n;
        n = s.nextInt();
        System.out.print("The term at index " + n + " is " + (a + (n - 1) * d));
        System.out.print("Sum is: " + SumOfAP(a, d, n));
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
