// JAVA code to find Largest_common_multiple of n elements of the array

import java.util.Scanner;
import java.util.Arrays;

class LCM 
{
    public static void main(String args[]) 
    {
        int n;
        Scanner s = new Scanner(System.in);
        System.out.println("Enter no. of elements in array:");
        n = s.nextInt();
        int a[] = new int[n];
        System.out.println("Enter all the elements:");
        for (int i = 0; i < n; i++) 
        {
            // Taking input from the user
            a[i] = s.nextInt(); 
        }
        int lcm = 1;
        for (int each: a) 
        {
            lcm = calculateLcm(lcm, each);
        }
        System.out.println("LCM for " + Arrays.toString(a) + " is : " + lcm);
    }

    // Calculating LCM by using GCD
    private static int calculateLcm(int lcm, int each) 
    {
        return lcm * each / gcd(lcm, each);
    }

    // Calculating GCD
    private static int gcd(int val1, int val2) 
    {
        if (val1 == 0 || val2 == 0)
            return 0;

        if (val1 == val2)
            return val1;

        if (val1 > val2)
            return gcd(val1 - val2, val2);
        return gcd(val1, val2 - val1);
    }
}

/*Enter no. of elements in array:
6
Enter all the elements:
1 2 3 4 5 6
LCM for [1, 2, 3, 4, 5, 6] is : 60*/
