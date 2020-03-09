// Ugly numbers are numbers whose only prime factors are 2, 3 or 5.

import java.util.Scanner;

class Ugly{
    //Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
    public static void main(String args[]){
        int num;
        boolean x = false;
        Scanner scan = new Scanner(System.in);
        num = scan.nextInt();
        while (num != 1) {  
            if (num % 5 == 0) { // To check if number is divisible by 5 or not
                num /= 5;  
            } 
            else if (num % 3 == 0) { // To check if number is divisible by 3 or not 
                num /= 3;  
            } 
            else if (num % 2 == 0) { // To check if number is divisible by 2 or not
                num /= 2;  
            } 
            else {  
                System.out.print("It is not an ugly number."); 
                x = true;  
                break;  
            }  
        } 
        if ( !x ){ 
            System.out.print("It is an ugly number.");
        }
    }
}

/*
number: 8
It is an ugly number.
*/
