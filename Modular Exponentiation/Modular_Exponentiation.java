import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.awt.Point;

public class Solution {
   public static long modex(long base,long exponent,long mod){
       if(base == 0){
           return 0;        // 0^x = 0
       }
       if(exponent == 0){
           return 1;        // x^0 = 1
       }
       if(exponent%2 == 0){
           long ans = modex(base,exponent/2,mod);   // a^b = (a^(b/2)*(a^(b/2)). This effectively reduces the no. of computations required.
           return (ans*ans)%mod;
       }
       return ((base%mod)*(modex(base,exponent-1,mod)))%mod; //  When exponent is odd, we reduce it by 1 to make it even and go in recursion.

   }

   public static void main(String[] args) {
       int base = 12;
       int exponent = 7;
       int mod = 17;
       System.out.println("("+base+"^"+exponent+")%"+mod+" = "+modex(base,exponent,mod));
   }
}
