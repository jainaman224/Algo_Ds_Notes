/*
    For octal number with n digits:
    dn-1 ... d3 d2 d1 d0
    The decimal number is equal to the sum of octal digits (dn) times their power of 8 (8n):
    decimal = d0×8^0 + d1×8^1 + d2×8^2 + ...
*/

import java.util.Scanner; 
import java.io.*; 

class Octal_To_Decimal 
{
    // driver program 
    public static void main(String[] args) 
    { 
        int num;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();

        int dec = 0; 
        int base = 1;

        while (num > 0) 
        { 
            int x = num % 10; 
            num = num / 10; 
            dec += x * base; 
            base = base * 8; 
        } 
        
        System.out.println(dec); 
    } 
} 

/*
Input:
1000
Output:
512
*/
