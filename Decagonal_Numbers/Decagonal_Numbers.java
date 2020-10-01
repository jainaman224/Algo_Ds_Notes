/*
    A decagonal number is a figurate number that extends the concept of 
    triangular and square numbers to the decagon (a ten-sided polygon).
    
    The n-th decagonal number is given by the formula:
    Dn = 4n^2 - 3n.
*/

import java.util.*; 
import java.util.Scanner;

class Decagonal_Numbers
{ 
    // To calculate decagonal number 
    static int decagonalnumber (int num)  
    { 
        // Using formula 
        return 4 * num * num - 3 * num; 
    } 

    public static void main(String[] args)  
    {     
        int num;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();
        System.out.println(num + " decagonal number : " + decagonalnumber(num)); 
    } 
} 

/*
Input:
6
output:
6 decagonal number : 126
*/
