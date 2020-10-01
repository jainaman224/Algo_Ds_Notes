/*
    Catalan numbers (Cn) are a sequence of natural numbers that
    occur in many places. The most important ones being that Cn
    gives the number of Binary Search Trees possible with n values.
    Cn is the number of full Binary Trees with n + 1 leaves.
    Cn is the number of different ways n + 1 factors can be 
    completely parenthesized.
*/

import java.util.Scanner; 

class Catalan_Numbers
{
    public static void main(String args[]) 
    {
        // n denotes the nth Catalan Number that we want to compute
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Catalan array stores the catalan numbers from 1....n
        int Catalan[] = new int[n + 1];

        // The first two values are 1 for this series
        Catalan[0] = 1;
        Catalan[1] = 1;

        /*
            For e.g if n = 5, then
            Cn = (Catalan(0) * Catalan(4)) + (Catalan(1) * Catalan(3))
            + (Catalan(2) * Catalan(2)) + (Catalan(3) * Catalan(1)) +
            (Catalan(4)* Catalan(0))
            We can see here that Catalan numbers form a recursive
            relation i.e for nth term, the Catalan number Cn is
            the sum of Catalan(i) * Catalan(n-i-1) where i goes from
            0...n-1. We can also observe that several values are getting
            repeated and hence we optimise the performance by applying
            memoization.
        */
        for (int i = 2; i <= n; i++) 
        {
            for (int j = 0; j < i; j++) 
                Catalan[i] += (Catalan[j] * Catalan[i - j - 1]);
        }

        // nth Catalan number is given by n - 1th index
        System.out.println("The Catalan Number (Cn) is: "+ Catalan[n - 1]);
    }
}

/*
    Input:
    10
    Output:
    The Catalan Number (Cn) is: 4862

    Input:
    5
    Output:
    The Catalan Number (Cn) is: 14
*/
