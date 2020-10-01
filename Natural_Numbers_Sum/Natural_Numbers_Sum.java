/*
    Sum of First N Natural Numbers

    The task is to find sum of first n natural numbers, where n is 
    the number input to us. We use the well known formula,
    sum = n * (n + 1)/2 to compute the sum

*/

import java.util.Scanner;

class Sum_Of_N_Natural_Numbers {
    
    public static void main(String args[]) {
        int num;
        System.out.print("Enter N: ");
        Scanner s = new Scanner(System.in);
        num = s.nextInt();
        int sum = num * (num + 1) / 2;
        System.out.print("The sum of first " + num + " natural numbers is : " + sum);
    }
}

/*
    Input : num = 6
    Output : The sum of first 6 natural numbers is : 21
*/
