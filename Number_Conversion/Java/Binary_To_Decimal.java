/*
    For binary number with n digits:
    dn-1 ... d3 d2 d1 d0
    
    The decimal number is equal to the sum of binary digits (dn) times their power of 2 (2n):
    decimal = d0×2^0 + d1×2^1 + d2×2^2 + ...
*/

import java.util.Scanner;

class Binary_To_Decimal
{ 
    static int binaryToDecimal(int num) 
    { 
        int decimal = 0; 

        int base = 1; 

        while (num > 0) 
        { 
            int x = num % 10; 
            num = num / 10; 

            decimal += x * base; 

            base = base * 2; 
        }
        return decimal; 
    } 

    public static void main(String[] args) 
    { 
        int num;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();
        System.out.println(binaryToDecimal(num)); 
    } 
}

/*
Input:
100
Output:
4
*/
