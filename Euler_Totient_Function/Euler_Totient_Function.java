/*
    Euler Totient Function.

    ETF (Euler Totient Function) of a number n is defined as the number of positive integers
    less than n, which are co-prime to n, i.e. 
    ETF(n) = frequency of x where gcd(x,n) = 1 and 1<=x<=n.

    Brute force approach : Iterate over all elements < n and check if it's co-prime to n.

    Our Approach : We use formula - ETF(n) = (1- 1/p1)*(1 - 1/p2).. where p1, p2 etc are 
                    prime factors of n.

*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.awt.Point;

public class Solution {
    public static double Etf(long num){
        double ans = num;
    /*
        In this loop, we check for all prime factors of num and keep removing the
        multiples of those prime factors from our scope of search and thus, with each 
        iteration, num gets reduced by an order of that factor.
    */
        for(long i=2; i <= Math.sqrt(num); i++){
            if(num%i == 0){
                ans *= (1 - (1.0/i));   // Using the ETF formula.
                while(num%i == 0){
                    num/=i;
                }
            }
        }
        ans = (( num > 1 ) ? (ans * (1 - (1.0/num))) : (ans));  
        // If there's any element left which is > sqrt(n), it can contribute maximum once.
        return ans;
    }
   
    public static void main(String[] args) {
        long num = 34;
        double etf = Etf(num);
        System.out.print("ETF of "+num+" is "+(int)etf);
    }
}
/*
Input : num = 34.
Output: ETF of 34 is 16
Verification : 1,3,5,7,9,11,13,15,19,21,23,25,27,29,31,33 are the numbers whose gcd with 34 is 1.

*/
