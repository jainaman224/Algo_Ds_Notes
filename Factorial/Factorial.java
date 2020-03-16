/* This code is used to find factorial of large numbers*/

import java.util.*;
import java.lang.*;
import java.math.*;
class Factorial 
{
    public static void main(String[] args) throws java.lang.Exception 
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        BigInteger f = new BigInteger("1");
        for (int j = 1; j <= n; j++) 
        {
            f = f.multiply(BigInteger.valueOf(j));
        }
        System.out.println(f);
    }
}

/*ENTER THE NUMBER
5
Answer is : 120*/
