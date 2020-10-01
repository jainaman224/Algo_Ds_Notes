/*
    A centered decagonal number is a centered figurate number that represents
    a decagon with a dot in the center and all other dots surrounding the center
    dot in successive decagonal layers. 
    
    The centered decagonal number for n is given by the formula
    5n^2+5n+1 
*/

import java.util.*; 
import java.util.Scanner;

class Centered_Decagonal_Numbers
{ 
    // To calculate centered decagonal number 
    static int centeredDecagonal (int num)  
    { 
        // Using formula 
        return 5 * num * num + 5 * num + 1; 
    } 

    public static void main(String[] args)  
    {     
        int num;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();
        System.out.println(num + " centered decagonal number : " + centeredDecagonal(num)); 
    } 
}

/*
Input:
6
output:
6 centered decagonal number : 211
*/
