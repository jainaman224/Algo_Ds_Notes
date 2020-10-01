// Perfect number is a positive integer that is equal to the sum of its proper divisors.

import java.util.Scanner; 
public class Perfect
{
    public static void main(String[] args) 
    {
        int sum = 0;
        Scanner input = new Scanner(System.in);    	
    	int num = input.nextInt();
        
        // Calculating the sum of divisors
        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                sum = sum + i;
            }
        }
        if (sum == num)
        {
            System.out.println("It is a perfect number");
        }
        else
        {
            System.out.println("It is not a perfect number");
        }    
    }
}

// INPUT: 28
// OUTPUT: It is a perfect number
