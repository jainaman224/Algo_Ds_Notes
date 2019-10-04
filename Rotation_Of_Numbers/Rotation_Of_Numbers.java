import java.util.*;

class Rotation_Of_Number
{ 
    // Function to rotations of a number 
    static void rotation(int num) 
    { 
        int temp = num;
        int digits = 0; 

        // Finding the number of digits
        while (temp > 0)
        { 
            digits++; 
            temp /= 10; 
        } 

        int power = (int) Math.pow(10, digits - 1); 

        // Rotations of the number
        for (int i = 0; i < digits - 1; i++) 
        {
            int lastDigit = num % 10; 
            int x = num / 10;
            num = lastDigit * power + x;
            System.out.print(num + " ");  
        } 
    } 

    // Driver Code 
    public static void main(String[] args) 
    { 
        Scanner sc = new Scanner(System.in); 
        int num = sc.nextInt();  
        rotation(num); 
    } 
} 

/*
Input:
1234
Output:
4123 3412 2341 
*/
