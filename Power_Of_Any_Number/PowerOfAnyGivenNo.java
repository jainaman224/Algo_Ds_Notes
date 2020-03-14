/*
*   Problem Statement
* Program to find if a No. is a power of any Given No. in Java
*	
*   Approach
*Comparing the log's value with the floor value of log 
*/

import java.util.Scanner;

public class PowerOfAnyGivenNo {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);	//input
        
        System.out.print("Enter a no. : ");
        int number = sc.nextInt();

        System.out.print("Check for which no. ? ");
        int base = sc.nextInt();

        if( isPowerOfGivenNo(number, base) )
            System.out.println("Yes " + number + " is a power of " + base);
        else
            System.out.println("No "+ number + " is not a power of " + base);

        sc.close();
    }

    private static boolean isPowerOfGivenNo(int number, int base) {

        if(number == 0)
        {	
        //0 power anything is 0
            if(base == 0)
                return true;
        //0 is not the power of any number	
            return false;
        }

        //explicitly check for 1 because log(1) = 0
        if(base == 1)
        {
            if(number == 1)
                return true;
            else	
                return false;
        }

        // -8 cannot be power of 2 but can be power of -2
        if( number < 0 && base > 0)
            return false;

        //converting to positive	
        number = Math.abs(number);
        base = Math.abs(base);

        float logValue = (float) ( Math.log(number) / Math.log(base) );
        return logValue == Math.floor(logValue);
    }

}

/*
* Input :
    Enter a no. : 14641
    Check for which no. ? 11

* Output :
    Yes 14641 is a power of 11
* */
