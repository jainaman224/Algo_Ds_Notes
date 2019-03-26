/*
    Prime Factorization of a number

    The task is to prime factorize a number using efficient techniques.
    i.e. denote a number as a product of different prime factors.

*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.awt.Point;

public class Solution {
    /*
        Since, 2 is the only even prime number, we compute it's frequence in the
        prime factorization of num separately, and then run the loop from 3, and 
        increment it by 2, so that we only check the odd numbers.
        In the loop, we keep decrementing the value of num by a factor of the number,
        which divides it.
        After the loop, if the value of num still tends to be greater than 2, it means,
        it is a prime factor in itself. Thus, we add to it's prime factors.
    */

    public static void prime_factorize(long num){
        List<Long> prime_factors = new ArrayList<Long>(); // To maintain the prime factors of the given number.
        while(num%2 == 0){
            prime_factors.add((long)2);
            num/=2;
        }
        for(long i=3;i*i<=num;i+=2){
            while(num%i == 0){
                prime_factors.add(i);
                num/=i;
            }
        }
        if(num>2){
            prime_factors.add(num);
        }
        // Printing the prime factors.
        for(int i=0;i<prime_factors.size();i++){
            System.out.print(prime_factors.get(i));
            if(i != prime_factors.size()-1){
                System.out.print(" * ");
            }
        }
    }

    public static void main(String[] args) {
        long num = 100;
        System.out.print(num+" = ");
        prime_factorize(num);
    }
}
/*
Input : num = 100.
Output: 100 = 2 * 2 * 5 * 5
*/
