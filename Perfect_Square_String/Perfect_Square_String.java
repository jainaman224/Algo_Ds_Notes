import java.io.*; 
import java.util.Scanner;

public class Perfect_Square_String
{ 
    static double perfectSquareString(String str) 
    { 
        int sum = 0; 

        // Length of the string 
        int length = str.length(); 

        // Calculating sum of the string by converting it in its ASCII value
        for (int i = 0; i < length; i++) 
            sum = sum + (int)str.charAt(i); 

        // Calculating square root
        double squareRoot = (double)Math.sqrt(sum); 

        // If square root is an integer 
        return squareRoot - Math.floor(squareRoot); 
    } 

    // Driver code 
    public static void main (String[] args) 
    { 
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine(); 

        if (perfectSquareString(str) == 0) 
            System.out.println("YES"); 
        else
            System.out.println("NO"); 
    } 
} 

/*
INPUT :
Q
OUTPUT :
YES
Becasue ASCII value of Q is 81 which is a perfect square
*/
