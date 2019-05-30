/*
Centered Square Number is a centered figurate number that gives the number
of dots in a square with a dot in the center and all other dots surrounding 
the center dot in successive square layers.
    
Nth Centered square number can be calculated by using formula n^2 + (n-1)^2.
*/

import java.util.*; 

class Centered_Square
{ 
    static int centeredSquare (int num)  
    { 
        // Using formula 
        return num * num + ((num - 1) * (num - 1)); 
    } 

    public static void main(String[] args)  
    {     
        int num;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();
        System.out.println(centeredSquare(num)); 
    } 
} 

/*
Input:
6
output:
61
*/
