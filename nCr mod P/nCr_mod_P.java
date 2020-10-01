/*
    nCr % p.

    The task is to find the binomial coefficient nCr under modulo p. The normal approach would
    be to first find nCr and then do modulo p, which is highly efficient for large numbers,
    and may cause overflow.
    Thus, we use dynamic programming approach to solve this problem.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.awt.Point;

public class Solution {
   public static long nCr(long n,long r,long mod){
        if(n<r){
            return -1;
        }
        // We create a pascal triangle.
        int size = (int)r+1;
        long Pascal[]=new long[size];
        Pascal[0]=1;
        for(int i=1;i<=r;i++){
            Pascal[i]=0;
        }
        // We use the known formula nCr = (n-1)C(r) + (n-1)C(r-1) for computing the values.
        for(long i=1;i<=n;i++){
            int k = (int)((i<r)?(i):(r)); // we know, nCr = nC(n-r). Thus, at any point we only need min
            for(int j=k;j>0;j--){ // of the two, so as to improve our computation time.
                Pascal[j] = (Pascal[j] + Pascal[j-1])%mod;
            }
        }
        return Pascal[size-1];
    }
   public static void main(String[] args) {
        long n = 7;
        long r = 5;
        long mod = 6;
        long ans = nCr(n,r,mod);
        if(ans == -1){
            System.out.println("Bad Input. N can never be less than R.");
        }
        else{
            System.out.println("The value of nCr("+n+","+r+")%"+mod+" is "+ans) ;
        }  
   }
}
/*
Input :  n = 7, r = 5, mod = 6.
Output: The value of nCr(7,5)%6 is 3
Verification : nCr(7,5) = 7!/((5!)(2!)) = 21
                21%6 = 3.

*/
