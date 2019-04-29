/*A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if
abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + .... */

import java.lang.Math;

public class Armstrong 
{ 	
    //To calculate the order of the number
    int order(int num) 
    { 
        int count = 0; 
        while (num != 0) 
        { 
            count++; 
            num = num / 10; 
        } 
        return count; 
    } 

    // Function to check whether the given number is 
    // Armstrong number or not 
    int Armstrong (int num) 
    { 
        int count = order(num); 
        int sum = 0; 
        while (num != 0) 
        { 
            int d = num % 10; 
            int x = (int)Math.pow(d,count) ;
            sum = sum + x; 
            num = num / 10; 
        } 
        return sum;
    } 

    // Driver Program 
    public static void main(String[] args) 
    { 
        Armstrong ob = new Armstrong(); 
        int num = 153;
        int sum = ob.Armstrong(num);
        
        if(sum == num)
            System.out.println("Armstrong number"); 
        else
            System.out.println("Not an Armstrong number"); 
    } 
} 

//Output : Armstrong number
