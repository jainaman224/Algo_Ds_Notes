/*The nth triangular number is the number of dots in the triangular arrangement 
with n dots on a side, and is equal to the sum of the n natural numbers from 1 to n.
We can check if a number is triangular number or not by solving a quadratic equation :
n^2 + n + (-2 * num) = 0 
where n is sum of first ‘n’ natural numbers
and num is the input number.
*/

import java.io.*; 

class Triangular_Number
{     
    public static void main (String[] args)
    { 
        int num = 10; 
        
        int a = 1, b = 1;
        int c = (-2 * num); 
        
        // Calculating discriminant
        int d = (b * b) - (4 * a * c); 

        if (d < 0) 
            System.out.println("The number is a triangular number"); 

        // Find roots of equation 
        float root1 = ((-b) + (float)Math.sqrt(d)) / (2 * a); 
        float root2 = ((-b) - (float)Math.sqrt(d)) / (2 * a); 

        // if root1 is natural and integer number than it is a triangular number
        if (root1 > 0 && Math.floor(root1) == root1) 
            System.out.println("The number is a triangular number"); 

        // if root2 is natural and integer number than it is a triangular number 
        else if (root2 > 0 && Math.floor(root2) == root2) 
            System.out.println("The number is a triangular number"); 
        else
            System.out.println("The number is not a triangular number"); 
    }
}

// OUTPUT:The number is a triangular number
