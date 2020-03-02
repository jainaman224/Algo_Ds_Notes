//JAVA program to convert Decimal integer to it's Binary form

import java.util.Scanner;

public class Decimal_to_binary {

    //Driver Code
    public static void main(String[] args){
        int n, rem;
        String Bin = "";    //String to store the binary number
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any decimal number:");
        n = sc.nextInt();   //Taking the decimal input

        if (n == 0){
            Bin = "0";
        }

        //Simultaneously storing the remainder when number divided by 2 in the string in reverse order
        while (n > 0){
            rem = n % 2;
            Bin = rem + Bin;
            n = n / 2;
        }
        System.out.println("Binary number:"+Bin);   //output
    }
}
//Input : 10 
//Output : 1010 

